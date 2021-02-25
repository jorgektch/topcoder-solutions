#include <bits/stdc++.h>
using namespace std;
class CreateMixture{
	public: string/*vector <int>*/ mix(int concentration){
		vector<int> digits(10,-1);
        while(){
            
        }
        return
	}
    public: double get_q(vector <int> v){
        int q = 0;
        int count = 0;
        for(int i=0; i<v.size();i++){
            if(v[i]!=-1){
                q += v[i]
                count++;
            }
        }
        return q/count;
    }
};
int main(){
	CreateMixture obj;
    cout << "Case 0: " << obj.mix(500) << " | " << "{0, 1, -1, 1, -1, 0, -1, -1, -1, -1 }" << endl;
    cout << "Case 1: " << obj.mix(250) << " | " << "{0, 1, -1, 1, -1, 0, -1, -1, -1, -1, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1 }" << endl;
    cout << "Case 2: " << obj.mix(0) << " | " << "{}" << endl;
    cout << "Case 3: " << obj.mix(400) << " | " << "{0, 1, -1, 1, -1, 0, -1, -1, -1, -1, 0, 0, 1, 2, 2, -1, -1, -1, -1, -1 }" << endl;
    cout << "Case 4: " << obj.mix(2) << " | " << "{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 3, -1, -1, -1, -1, -1 }" << endl;
	return 0;
}