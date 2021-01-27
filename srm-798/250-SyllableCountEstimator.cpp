#include <bits/stdc++.h>
using namespace std;
class SyllableCountEstimator{
  public: int estimate(string W){
      int vocals = 0;
        for(int i=0; i<W.length(); i++){
            if(W[i]=='a'||W[i]=='e'||W[i]=='i'|| W[i]=='o'||W[i]=='u') vocals++;
        }
        for(int i=0; i<W.length()-1; i++){
            if(W[i]=='a' && W[i+1]=='u') vocals--;
            if(W[i]=='o' && W[i+1]=='a') vocals--;
            if(W[i]=='o' && W[i+1]=='o') vocals--;
            if(W[i-1]=='i' && W[i]=='o' && W[i+1]=='u') vocals--;
        }
        if(W[W.length()-1]=='e') vocals--;
        if(W.length()>=3){
            if(W[W.length()-2]=='l' && W[W.length()-1]=='e'){
                if(W[W.length()-3]!='a'&& W[W.length()-3]!='e'&& W[W.length()-3]!='i'&& W[W.length()-3]!='o'&& W[W.length()-3]!='u')
                vocals++;
            }
        }
        if(vocals == 0){
            return 1;
        }else{
            return vocals;
        }
    }
};