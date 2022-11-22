#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int> &s, int x){

    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s,x);

    s.push(num);

}



int main(){

    int x;
    cout << "Enter the element : ";
    cin>>x;

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int n = s.size();

    insertAtBottom(s, x);
 
    while(!s.empty()){

        cout << s.top() << endl;
        s.pop();

    }



    return 0;
}