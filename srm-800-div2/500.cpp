#include <bits/stdc++.h>
using namespace std;
class SlotMachineHacking{
	public: int win(vector <string> reels, vector <int> steps){
		
        return
	}
};
int main(){
	SlotMachineHacking obj;
    cout << "Case 0: " << obj.win({"abc", "acb", "cab"}, {32, 31, 30}) << " | " << "0" << endl;
    cout << "Case 1: " << obj.win({"abc", "acb", "cab"}, {30, 33, 300000006}) << " | " << "-1" << endl;
    cout << "Case 2: " << obj.win({"abc", "bac", "abpc"}, {1, 1, 1}) << " | " << "10" << endl;
    cout << "Case 3: " << obj.win({"aac", "aac", "aaac"}, {1, 1, 1}) << " | " << "10" << endl;
	return 0;
}