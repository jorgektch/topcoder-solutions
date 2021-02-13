#include <bits/stdc++.h>
using namespace std;
class TIEFighterAssembly{
	public: int assemble(string salvagedParts){
		map<char, int> count;
        count['|'] = 0;
        count['O'] = 0;
        count['-'] = 0;

        for(int i=0; i<salvagedParts.size(); i++){
            if(salvagedParts[i]=='|')
                count['|']++;
            if(salvagedParts[i]=='O')
                count['O']++;
            if(salvagedParts[i]=='-')
                count['-']++;
        }
        return min(count['O'], min(count['|']/2, count['-']/2));
	}
};
int main(){
	TIEFighterAssembly obj;
    cout << "Case 0: " << obj.assemble("|-O-|") << " | " << "1" << endl;
    cout << "Case 1: " << obj.assemble("||--O") << " | " << "1" << endl;
    cout << "Case 2: " << obj.assemble("|||||-----OOO") << " | " << "2" << endl;
    cout << "Case 3: " << obj.assemble("=+()*=+()*=+()*") << " | " << "0" << endl;
    cout << "Case 4: " << obj.assemble("||+||-||+||-||+||-||+||-") << " | " << "0" << endl;
    cout << "Case 5: " << obj.assemble("===O|O-O|O-O|O===") << " | " << "1" << endl;
	return 0;
}