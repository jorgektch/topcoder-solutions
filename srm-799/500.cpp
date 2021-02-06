#include <bits/stdc++.h>
using namespace std;
class PlanningTrips{
    public: int find(int a, vector <int> num){
        long long int acum = 0;
        for(int i=0; i<num.size(); i++){
            acum += pow(a, num[i]);
        }
        return ceil(log10(acum)/log10(a));
    }
};
int main(){
    PlanningTrips obj;
    cout << "Case 1: " << obj.find(10, {5, 6, 3}) << " | " << "7" << endl;
    cout << "Case 2: " << obj.find(2, {13, 13}) << " | " << "14" << endl;
    cout << "Case 3: " << obj.find(2, {13, 0, 13}) << " | " << "15" << endl;
    return 0;
}