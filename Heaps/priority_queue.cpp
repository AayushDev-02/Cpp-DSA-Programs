#include <iostream>
#include <queue>

using namespace std;

int main(){

    // using priority queue

    //this is a max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Element at top : " << pq.top() << endl;
    pq.pop();
    cout << "Element at top : " << pq.top() << endl;

    // size
    cout << "Size of the priority queue is: " << pq.size() << endl;

    if(pq.empty()){
        cout << "Size is empty" << endl;
    }
    else{
        cout << "Size is not empty" << endl;
    }

    cout << endl;
    cout << endl;

    // MIN HEAP
    priority_queue<int, vector<int>, greater<int> > minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout << "Element at top : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Element at top : " << minHeap.top() << endl;

    // size
    cout << "Size of the priority queue is: " << minHeap.size() << endl;

    if(pq.empty()){
        cout << "Size is empty" << endl;
    }
    else{
        cout << "Size is not empty" << endl;
    }

    return 0;
}