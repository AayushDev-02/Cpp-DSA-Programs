#include <iostream>
#include <stack>
using namespace std;

int main(){

    string str="";
    cout << "Enter string: "<< endl;

    cin>>str;

    stack<char> s;

    for(auto it: str){
        s.push(it);
        cout << it << " ";
    }
    cout<<endl;

    string ans="";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout << "Reverse of string is: " << ans << endl;

    return 0;
}