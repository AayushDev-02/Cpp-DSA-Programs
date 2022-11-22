#include <iostream>
#include <stack>
using namespace std;

bool isValidParenrhesis(string str){

    stack<char> s;

    for(int i=0; i<str.length(); i++){

        char ch=str[i];

        //opening bracket
        if(ch == '(' || ch == '{' || ch=='[') {
            s.push(ch);
        }
        //for closing bracket
        else{

            if(!s.empty()){

                char top = s.top();

                if( (ch == ')' && top == '(' ) || (ch == '}' && top == '{') || (ch == '[' && top == ']')){
                    s.pop();

                }else{
                    return false;
                }

            }
            else{
                return false;
            }

        }   

    }

    if(s.empty()){
        return true;
    }else{  
        return false;   
    }


}


int main(){

    string str="";
    cout << "Enter string expression of parenthesis: ";
    cin >> str;

    bool ans = isValidParenrhesis(str);
    
    if(ans){
        cout << "Expression is balanced " << endl;
    }else{
        cout << "Expression is unbalanced " << endl;
    }

    return 0;
}