#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s,x);

    s.push(num);

}


void reverse(stack<int> &s){

    //base case
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();
    //recursive call
    reverse(s);

    insertAtBottom(s,num);

}



int main(){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverse(s);
 
    while(!s.empty()){

        cout << s.top() << endl;
        s.pop();

    }



    return 0;
}