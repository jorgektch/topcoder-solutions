import java.awt.*;
import java.awt.geom.*;
import java.util.*;
import java.io.*;
import javax.imageio.*;
import java.util.List;
import java.util.ArrayList;

import com.topcoder.marathon.*;

public class JewelsTester extends MarathonAnimatedVis {
    //parameter ranges
    private static final int minN = 8, maxN = 16;
    private static final int minC = 5, maxC = 10;

    //Inputs
    private int N;      //grid size
    private int C;      //number of colors

    //Manual play
    private int lastR1;
    private int lastC1;
    private int lastR2;
    private int lastC2;

    //Constants 
    private static final int maxMoves = 1000;

    //Graphics
    Image[] JewelPic = new Image[maxC];

    //State Control
    private ArrayList<Integer>[] Grid; 
    private boolean gameOver;
    private int numMoves;
    private int score;
    private int moveScore;

    protected void generate() {
        N = randomInt(minN, maxN);
        C = randomInt(minC, maxC);

        //Special cases
        if (seed == 1)
        {
          N = minN;
          C = minC;
        }
        else if (seed == 2)
        {
          N = maxN;
          C = maxC;
        }    
        
        //User defined parameters   
        if (parameters.isDefined("N"))
        {
          N = randomInt(parameters.getIntRange("N"), minN, maxN);
        }
        if (parameters.isDefined("C"))
        {
          C = randomInt(parameters.getIntRange("C"), minC, maxC);
        }
              
        Grid = new ArrayList[N];
        for (int i=0;i<N;i++)
          Grid[i] = new ArrayList<Integer>();
        for (int c=0;c<N;c++) 
        {
          for (int r=0;r<maxMoves*N;r++)
          {
            Grid[c].add(randomInt(1, C));
          }
        }
        // Let things settle, remove matching jewels
        numMoves = 0;
        int tmp = applyMove(0, 0, 0, 0);
       
        //display grid for debugging
        if (debug)
        {
          System.out.println("Grid:");          
          for (int r=0; r<N; r++)
          {
            for (int c=0; c<N; c++)        
              System.out.print(Grid[c].get(N-1-r)+" ");
            System.out.println();
          }        
        }
          
        gameOver = false;
        
        if (debug) 
        {
          System.out.println("Grid Size N = " + N);
          System.out.println("Colors C = " + C);
        }
    }
    
    protected boolean isMaximize() {
        return true;
    }
    
    protected double run() throws Exception
    {
      init();
    
      if (parameters.isDefined("manual"))
      {
        setDefaultDelay(0);     //TODO: doesn't seem to work :(
        return 0;
      }
      else return runAuto();
    }
    
    
    protected double runAuto() throws Exception
    {
      score = callSolution();
      if (score < 0) {
        if (!isReadActive()) return getErrorScore();
        return fatalError();
      }
      return score;    
    }    

    protected void updateState()
    {
      if (numMoves>0 && hasVis() && (hasDelay() || !gameOver)) 
      {      
        synchronized (updateLock) 
        {
          addInfo("Moves", numMoves);
          addInfo("Score", score);
          addInfo("Last Move Score", moveScore);
          addInfo("Time", getRunTime());
        }
        updateDelay();
      }
    }

    protected void contentClicked(double x, double y, int mouseButton, int clickCount)
    {
      if (!parameters.isDefined("manual")) return;
      if (gameOver) return;             //game is over
      
      int r=(int)Math.floor(y);
      int c=(int)Math.floor(x);
      if (!inGrid(r,c)) return;         //not in grid

      if (mouseButton == java.awt.event.MouseEvent.BUTTON1)
      {
        if (lastR1==-1)
        {
          lastR1 = r;
          lastC1 = c;
        } else
        {
          if (r==lastR1 && c==lastC1)
          {
            //undo
            lastR1 = lastC1 = -1;
          } else
          {
            lastR2 = r;
            lastC2 = c;
            numMoves++;
            //apply the move
            moveScore = applyMove(N-1-lastR1, lastC1, N-1-lastR2, lastC2);
            score += moveScore;

            updateState();
            lastR1 = lastC1 = lastR2 = lastC2 = -1;
          }
        }
      }
      updateState();
    }    
    
    protected void timeout() {
        addInfo("Score", "-1 (Timeout)");
        addInfo("Time", getRunTime());
        update();
    }    
    
    protected boolean inGrid(int r, int c)
    {
      return (r>=0 && r<N && c>=0 && c<N);
    }
    
    private void writeGrid() throws Exception {
        for (int r=0; r<N; r++)
        {
          for (int c=0; c<N; c++)        
            writeLine(""+Grid[c].get(r));
        }  
    }

    private int getLineScore(int matches)
    {
      return (matches-2)*(matches-2);
    }

    private int applyMove(int r1, int c1, int r2, int c2) 
    {
      moveScore = 0;
      // swap jewels
      updateState(); // This will draw the rectangles showing which cells will be swapped
      int tmp = Grid[c1].get(r1);
      Grid[c1].set(r1, Grid[c2].get(r2));
      Grid[c2].set(r2, tmp);
      updateState(); // This will draw the swapped rectangles
      boolean Matched = false;
      int combo = 0;
      do
      {
        Matched = false;
        java.util.List<Integer> matchR = new ArrayList<Integer>();
        java.util.List<Integer> matchC = new ArrayList<Integer>();
        // Find any rows with 3 or more matching jewels
        for (int r=0;r<N;r++)
        {
          int match = 0;
          for (int c=1;c<N;c++)
          {
            if (Grid[c].get(r)==Grid[c-1].get(r))
            {
              match++;
            } else
            {
              if (match>=2)
              {
                moveScore += getLineScore(match+1);
                for (int cc=0;cc<=match;cc++)
                {
                  matchR.add(r);
                  matchC.add(c-1-cc);
                }
              }
              match = 0;
            }
          }
          if (match>=2)
          {
            moveScore += getLineScore(match+1);
            for (int cc=0;cc<=match;cc++)
            {
              matchR.add(r);
              matchC.add(N-1-cc);
            }
          }
        }
        // Find any columns with 3 or more matching jewels
        for (int c=0;c<N;c++)
        {
          int match = 0;
          for (int r=1;r<N;r++)
          {
            if (Grid[c].get(r)==Grid[c].get(r-1))
            {
              match++;
            } else
            {
              if (match>=2)
              {
                moveScore += getLineScore(match+1);
                for (int rr=0;rr<=match;rr++)
                {
                  matchR.add(r-1-rr);
                  matchC.add(c);
                }
              }
              match = 0;
            }
          }
          if (match>=2)
          {
            moveScore += getLineScore(match+1);
            for (int rr=0;rr<=match;rr++)
            {
              matchR.add(N-1-rr);
              matchC.add(c);
            }
          }
        }

        // Let jewels fall
        if (matchR.size()>0)
        {
          Matched = true;
          // Remove matched cells
          for (int i=0;i<matchR.size();i++)
          {
            Grid[matchC.get(i)].set(matchR.get(i),-1);
          }
          lastR1 = lastR2 = -1; // remove the display of the selection rectangles.
          updateState(); // This will draw the removed cells for this turn

          combo++; // count the combo's
          for (int r=N-1;r>=0;r--)
          {
            boolean bFell = false;
            for (int c=0;c<N;c++)
            if (Grid[c].get(r)==-1)
            {
              Grid[c].remove(r);
              bFell = true;
            }
            if (bFell)
            {
              updateState(); // If something in this row fell, visualize it
            }
          }
        }        
      } while (Matched);
      return moveScore * combo;
    }

    private int callSolution() throws Exception {
        writeLine(N);
        writeLine(C);
        writeGrid();
        flush();
        if (!isReadActive()) return -1;
        
        if (hasVis() && hasDelay()) {
            synchronized (updateLock) {        
            }
            updateDelay();
        }               

        numMoves = 0;
        score = 0;        
        while ((numMoves < maxMoves) && !gameOver)
        {
          startTime();
          String move = readLine();
          stopTime();
            
          //get move
          int r1, c1, r2, c2;
          try
          {
            String[] temp=move.split(" ");
            if (temp.length!=4)
            {
              setErrorMessage("Error reading move: "+move);
              return -1;            
            }
            r1 = Integer.parseInt(temp[0]);
            c1 = Integer.parseInt(temp[1]);
            r2 = Integer.parseInt(temp[2]);
            c2 = Integer.parseInt(temp[3]);
          }
          catch(Exception e)
          {
            setErrorMessage("Error reading move: "+move);
            return -1;
          }
          if (!inGrid(r1,c1) || !inGrid(r2,c2) || (r1==r2 && c1==c2))
          {
            setErrorMessage("Invalid coordinates of move: "+move);
            return -1;          
          }
          
          //if we are here then the move was valid
          numMoves++;
          //apply the move
          lastC1 = c1;
          lastR1 = N-1-r1; // visualizer shows the grid up-side down
          lastC2 = c2;
          lastR2 = N-1-r2;
          moveScore = applyMove(r1, c1, r2, c2);
          score += moveScore;
            
          if (debug)
          {
            System.out.println("Move #" + numMoves + ": " + move);
          }            
          
          writeGrid();
          writeLine(""+getRunTime());
          flush();
        }
        gameOver=true;

        return score;
    }
     

    protected void paintContent(Graphics2D g) {
           
      g.setStroke(new BasicStroke(0.005f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));              
      g.setColor(Color.white);

      //draw grid
      for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
        { 
          int jewel = Grid[c].get(N-1-r);
          if (jewel>=0)
            g.drawImage(JewelPic[jewel-1],c,r,1,1,null);
          else
            g.fillRect(c, r, 1, 1);
        }
        
      if (lastR1!=-1)
      {
        g.setColor(Color.red);
        g.setStroke(new BasicStroke(0.05f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
        g.drawRect(lastC1, lastR1, 1, 1);
      }
      if (lastR2!=-1)
      {
        g.setColor(Color.red);
        g.setStroke(new BasicStroke(0.05f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
        g.drawRect(lastC2, lastR2, 1, 1);
      }
    }

    private void init() {

      numMoves = 0;
      score = 0;  
      moveScore = 0;
      if (hasVis())
      {
        for (int i=0;i<maxC;i++)
        {
          JewelPic[i] = loadImage("images/jewel"+(i+1)+".png");
        }

        lastR1 = lastC1 = lastR2 = lastC2 = -1;
        setContentRect(0, 0, N, N);
        setInfoMaxDimension(20, 10);
        setDefaultDelay(200);

        addInfo("Seed", seed);
        addInfoBreak();
        addInfo("Size N", N);
        addInfo("Colors C", C);
        addInfoBreak();           
        addInfo("Moves", "-");
        addInfo("Score", "-");
        addInfo("Last Move Score", "-");
        addInfoBreak();
        addInfo("Time", "-");
        update();
      }
    }
    
    Image loadImage(String name) {
      try{
        Image im=ImageIO.read(new File(name));
        return im;
      } catch (Exception e) { 
        return null;  
      }             
    }  

    public static void main(String[] args) {
        new MarathonController().run(args);
    }
}
