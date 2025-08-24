#include <iostream>
#include <stack>
using namespace std;
 int main(){
    stack<int> stack;
    int dec;
    cout<<"Enter decimal integer : ";cin>>dec;
    for(;dec>0;dec/=2) stack.push(dec%2);
    while(!stack.empty()){
        cout<<stack.top();
        stack.pop();
    }
 }
