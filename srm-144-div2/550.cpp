#include <bits/stdc++.h>
using namespace std;
class BinaryCode{
    public: string decode_if(string message, string first){
        string p = first; int last_sum = 0+(p[0]-'0');
        int i=1; int n=message.size(); bool is_possible = true;
        while(i<n && is_possible){
            int pi = (message[i-1]-'0')-(last_sum);
            if(pi==0 || pi==1){
                p+=to_string(pi);
                last_sum = (p[i]-'0')+(p[i-1]-'0');
            }else{
                is_possible = true;
            }
            i++;
        }
        if((message[n-1]-'0')!=((p[n-1]-'0')+(p[n-2])-'0'))
            is_possible = false;
        if(is_possible) return p;
        else return "NONE";
    }
	public: vector <string> decode(string message){
        vector<string> output;
        output.push_back(decode_if(message, "0"));
        output.push_back(decode_if(message, "1"));
        return output;
	}
};
int main(){
	BinaryCode obj;
    cout << "Case 0: ";
    for(int i=0; i<obj.decode("123210122").size(); i++)
        cout << obj.decode("123210122")[i] << " ";
    cout << " | " << "{ 011100011, NONE }" << endl;

    cout << "Case 1: ";
    for(int i=0; i<obj.decode("11").size(); i++)
        cout << obj.decode("11")[i] << " ";
    cout << " | " << "{ 01, 10 }" << endl;

    cout << "Case 2: ";
    for(int i=0; i<obj.decode("22111").size(); i++)
        cout << obj.decode("22111")[i] << " ";
    cout << " | " << "{ NONE, 11001 }" << endl;

    cout << "Case 3: ";
    for(int i=0; i<obj.decode("123210120").size(); i++)
        cout << obj.decode("123210120")[i] << " ";
    cout << " | " << "{ NONE, NONE }" << endl;

    cout << "Case 4: ";
    for(int i=0; i<obj.decode("3").size(); i++)
        cout << obj.decode("3")[i] << " ";
    cout << " | " << "{ NONE, NONE }" << endl;

    cout << "Case 5: ";
    for(int i=0; i<obj.decode("12221112222221112221111111112221111").size(); i++)
        cout << obj.decode("12221112222221112221111111112221111")[i] << " ";
    cout << " | " << "{ 01101001101101001101001001001101001, 10110010110110010110010010010110010 }" << endl;

	return 0;
}