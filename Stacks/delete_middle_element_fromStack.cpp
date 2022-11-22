#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &s, int count, int n){

    //base case
    if( count == n/2){
        s.pop();
        return;
    }

    int x = s.top();
    s.pop();

    //recursive call
    deleteMiddle(s , count + 1 , n) ;
    s.push(x);

}

int main(){

    stack <int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    
    int count=0;
    int n = s.size();
    deleteMiddle(s, count, n);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;


}