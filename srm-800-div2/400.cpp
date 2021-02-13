#include <bits/stdc++.h>
using namespace std;
class SlotMachineHacking{
	public: int win(vector <string> reels, vector <int> steps){
		int n=reels.size();
		for(int i=0; i<n; i++)
			steps[i] = steps[i]%reels[i].size();
		vector<int> current(n, 0);
		int answer = 0;
		while(true){
			for(int i=0; i<n; i++)
				current[i] = (current[i]+steps[i])%reels[i].size();
			for(int i=0; i<n; i++)
				if(reels[i][current[i]]!='c')
					goto notThisOne;
			return answer;
			notThisOne:;
			answer++;
			for(int i=0; i<n; i++)
				if(current[i])
					goto somethingNew;
			break;
			somethingNew:;
		}
		return -1;
	}
};
int main(){
	SlotMachineHacking obj;
    cout << "Case 0: " << obj.win({"abc", "acb", "cab"}, {32, 31, 30}) << " | " << "0" << endl;
    cout << "Case 1: " << obj.win({"abc", "acb", "cab"}, {30, 33, 300000006}) << " | " << "-1" << endl;
    cout << "Case 2: " << obj.win({"abc", "bac", "abpc"}, {1, 1, 1}) << " | " << "10" << endl;
    cout << "Case 3: " << obj.win({"aac", "aac", "aaac"}, {1, 1, 1}) << " | " << "10" << endl;
    cout << "Case 4: " << obj.win({"c", "c", "ababcbabab", "c"}, {470, 4700, 47002, 470000}) << " | " << "1" << endl;
    cout << "Case 5: " << obj.win({"ca", "caba"}, {1, 2}) << " | " << "1" << endl;
	return 0;
}