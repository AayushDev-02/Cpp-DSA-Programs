#include <iostream>
#include <stack>
using namespace std;

int main(){

    //creation if stack
    stack<int> s;

    //push
    s.push(10);
    s.push(20);

    //pop
    s.pop();

    cout << "Printing top element " << s.top() << endl ;

    //check if empty
    if(s.empty()){
        cout << "Stack is empty " << endl; 
    }else {
        cout << "Stack is NOT empty " << endl; 
    }


    //size
    cout << "Size of stack is: " << s.size() << endl;
    return 0;

}