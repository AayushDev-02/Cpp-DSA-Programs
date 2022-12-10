#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int> interLeave(queue<int> q){

   stack<int> s;

    int size = q.size();
    bool odd = false;
    int x= size/2;
    if(size%2 != 0){
        odd = true;
    }
    

    for(int i=0; i<x ; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i=0; i<(size-x); i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    for(int i=0; i<x; i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }

    if(odd){
        q.push(q.front());
        q.pop();
    }

    return q;
    
}



int main(){

    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    // q.push(18);

    queue<int> ans = interLeave(q);

    while(!ans.empty()){
        cout << ans.front() << endl;
        ans.pop();
    }

    return 0;
}