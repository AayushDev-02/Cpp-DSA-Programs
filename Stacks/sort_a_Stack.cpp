#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>&s, int x){

    if( (s.empty()) || (!s.empty() && x > s.top()) ){
        s.push(x);
        return;
    }
    
    int num= s.top();
    s.pop();

    sortedInsert(s,x);

    s.push(num);



}

void sortStack(stack<int> &s){

    //base case
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();
    //recursive call
    sortStack(s);

    sortedInsert(s,num);  

}



int main(){

    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);
 
    while(!s.empty()){

        cout << s.top() << endl;
        s.pop();

    }



    return 0;
}