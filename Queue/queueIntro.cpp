#include <iostream>
#include <queue>
using namespace std;

int main(){

    //create a queue
    queue<int> q;

    //pushing in queue
    q.push(15);

    cout << "Front of queue is : " << q.front() << endl;

    q.push(13);
    cout << "Front of queue is : " << q.front() << endl;

    q.push(20);
    cout << "Front of queue is : " << q.front() << endl;

    // size of queue
    cout << "Size of queue is: " << q.size() << endl;

    // Popping a element in queue
    q.pop();

    // size of queue
    cout << "Size of queue is: " << q.size() << endl;

    // checking if empty or not ?
    if(q.empty()){
        cout << "Queue is empty! " << endl;
    }else{
        cout << "Queue is not empty! " << endl;
    }

    // front element
    cout << "Front element is : " << q.front() << endl;

    

}