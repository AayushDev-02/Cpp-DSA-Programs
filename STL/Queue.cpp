#include <iostream>
#include <queue>
using namespace std;


int main(){

    queue<string> q;
    q.push("Aayush");
    q.push("PAPA");
    q.push("Mummy");
    q.push("fejkn");

    cout<<"Size before pop: "<<q.size()<<endl;
    cout<<"First Element: "<<q.front()<<endl;
    q.pop();
    cout<<"First Element: "<<q.front()<<endl;
    cout<<"Size before pop: "<<q.size()<<endl;

    return 0;
}