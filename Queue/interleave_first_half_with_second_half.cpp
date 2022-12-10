#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int> interLeave(queue<int> q){

    queue<int> temp;
    int s = q.size();

    bool odd = 0;
    
    if(s%2 != 0){
        odd = 1;
    }

    for(int i=0; i<s/2; i++){
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty()){
        int val = temp.front();
        temp.pop();
        q.push(val);

        val = q.front();
        q.pop();
        q.push(val);
    }

    if(odd == 1){
        int val = q.front();
        q.pop();
        q.push(val);
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