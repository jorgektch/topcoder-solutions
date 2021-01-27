#include<bits/stdc++.h>
using namespace std;
class FriendFinder{
    public:  int distance(string line){
        int pos = -1;
      for(int i=0; i<line.length(); i++){
            if(line[i]=='S' || line[i]=='F'){
              if(pos==-1){
                  pos = i;
                }else{
                  pos = i-pos;
                }
            }
        }
        return pos;
    }
};