#include <bits/stdc++.h>
using namespace std;
class CoolPairsEasy{
    public: int count(vector <string> firstname, vector <string> lastname){
        int count = 0;
        for(int i=0; i<firstname.size(); i++){
            for(int j=0; j<firstname.size(); j++){
                if(i!=j && lastname[i] == firstname[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    CoolPairsEasy obj;
    cout << "Case 1: " << obj.count({"elton", "tom", "john"},{"john", "jones", "cena"}) << " | " << "1" << endl;
    cout << "Case 2: " << obj.count({"james", "taylor"}, {"taylor", "james"}) << " | " << "2" << endl;
    cout << "Case 3: " << obj.count({"jar"}, {"jar"}) << " | " << "0" << endl;
    cout << "Case 4: " << obj.count({"lee", "stan", "ang", "marvin", "lee", "grace", "kelly", "jeremy"}, {"marvin", "lee", "lee", "gaye", "mack", "kelly", "clarkson", "clarkson"}) << " | " << "6" << endl;
    return 0;
}