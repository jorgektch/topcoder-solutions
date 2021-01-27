// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() 
{
  int N;
  int C;

  cin >> N;
  cin >> C;
  vector<int> grid(N*N);
  for (int i=0; i<N*N; i++)
  {
    cin >> grid[i];
  }  
  
  for (int i=0;i<1000;i++)
  {
    int r1 = 0;
    int c1 = i%N;
    int r2 = 1+(i%(N-1));
    int c2 = c1;
    cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    cout.flush();
    for (int j=0; j<N*N; j++)
    {
      cin >> grid[j];
    }
    int runtime;
    cin >> runtime;
  }
}