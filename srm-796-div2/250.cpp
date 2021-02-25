#include <bits/stdc++.h>
using namespace std;
class ChristmasCrackerHappiness{
	public: int solve(int N, vector <int> winner, vector <int> loser){
        map<int, bool> m;
		for(int i=0; i<winner.size(); i++){
            m[winner[i]] = true;
        }
        if(N-m.size()==0) return 0;
        else return N-m.size()-1;
	}
};
int main(){
	ChristmasCrackerHappiness obj;
    cout << "Case 0: " << obj.solve(2,{}, {}) << " | " << "1" << endl;
    cout << "Case 1: " << obj.solve(5, {0, 1, 0, 3, 2, 0, 4, 0}, {3, 3, 4, 1, 0, 2, 1, 3}) << " | " << "0" << endl;
    cout << "Case 2: " << obj.solve(12, {3, 1, 4, 1, 5, 9, 2, 6}, {5, 3, 5, 8, 9, 7, 9, 3}) << " | " << "4" << endl;
    // cout << "Case 3: " << obj.solve(input) << " | " << "output" << endl;
	return 0;
}