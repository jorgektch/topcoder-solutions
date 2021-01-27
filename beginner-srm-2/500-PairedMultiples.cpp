#include<bits/stdc++.h>
using namespace std;
class PairedMultiples{
    public:  int selectedTotal(vector <int> values, int multiple){
        int n = values.size();
        vector <int> cont(n,0);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((values[i]+values[j])%multiple == 0){
                    cont[i]=1;
                    cont[j]=1;
                }
            }
        }
        int suma = 0;
        for(int i=0; i<n; i++){
            suma += values[i]*cont[i];
        }
        return suma;
    }
};