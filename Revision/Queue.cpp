#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    queue<int> q;

    //insertion 
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout << "Size: " << q.size() << endl;

    //popping
    q.pop();
    cout << "Size: " << q.size() << endl;

    //printing
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl; 
    
    if(q.empty()){
        cout << "Queue is empty" << endl;
    }




    return 0;
}