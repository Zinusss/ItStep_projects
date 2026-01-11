#include <iostream>
#include <string>
using namespace std;
int main(){
 int num1, num2, res;
 char op;
 
cout << "Enter first: ";
 cin >> num1;

 cout << "Enter operator: ";
 cin >> op;
 cout << "Enter second: ";
 cin >> num2;

 if(op == '+'){
    res = num1 + num2;
 } else if(op == '-'){
    res = num1 - num2;
 } else if(op == '*'){
    res = num1 * num2;
 } else if(op == '/'){
    res = num1 / num2;
 }
 cout << "Result: " << res << endl;
 return 0;
}
