#include <bits/stdc++.h>
using namespace std;
class ClassName{
  public: string FunctionName(string name){
      string message = "hi";
      return message+" "+name;
  }
};
int main(){
    ClassName obj;
    cout << "Case 1: " << obj.FunctionName("Jorge") << " | " << "Esperado" << endl;
    cout << "Case 2: " << obj.FunctionName("Jesus") << " | " << "Esperado" << endl;
    cout << "Case 3: " << obj.FunctionName("Ktch") << " | " << "Esperado" << endl;
    cout << "Case 4: " << obj.FunctionName("Villaverde") << " | " << "Esperado" << endl;
    return 0;
}