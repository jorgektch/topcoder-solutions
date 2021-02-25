#include <bits/stdc++.h>
using namespace std;
class HouseNumbering{
	public: vector <int> prepareDigits(int firstHouse, int numberOfHouses){
		vector<int> numbers;
        for(int i=0; i<numberOfHouses; i++){
            numbers.push_back(firstHouse+2*i);
        }
        vector<int> digits(10,0);
        for(int i=0; i<numbers.size(); i++){
            for(auto digit: to_string(numbers[i])){
                digits[digit-'0']++;
            }
        }
        return digits;
	}
};
int main(){
	HouseNumbering obj;
    cout << "Case 0: " << obj.prepareDigits(7,4) << " | " << "{0, 3, 0, 1, 0, 0, 0, 1, 0, 1}" << endl;
    cout << "Case 1: " << obj.prepareDigits(2,6) << " | " << "{1, 2, 2, 0, 1, 0, 1, 0, 1, 0}" << endl;
    cout << "Case 2: " << obj.prepareDigits(997,1) << " | " << "{0, 0, 0, 0, 0, 0, 0, 1, 0, 2}" << endl;
    cout << "Case 3: " << obj.prepareDigits(160,47) << " | " << "{15, 25, 42, 5, 14, 2, 14, 5, 14, 5}" << endl;
	return 0;
}