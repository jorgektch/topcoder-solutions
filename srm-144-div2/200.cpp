#include <bits/stdc++.h>
using namespace std;
class Time{
	public: string whatTime(int seconds){
		string text = "";
        int secongs_rest = seconds;
        int h = secongs_rest/3600; secongs_rest -= h*3600;
        int m = secongs_rest/60; secongs_rest -= m*60;
        int s = secongs_rest;
        return text+to_string(h%24)+":"+to_string(m)+":"+to_string(s);
	}
};
int main(){
	Time obj;
    cout << "Case 0: " << obj.whatTime(0) << " | " << "0:0:0" << endl;
    cout << "Case 1: " << obj.whatTime(3661) << " | " << "1:1:1" << endl;
    cout << "Case 2: " << obj.whatTime(5436) << " | " << "1:30:36" << endl;
    cout << "Case 3: " << obj.whatTime(86399) << " | " << "23:59:59" << endl;
	return 0;
}