#include <iostream>
#include <queue>

using namespace std;

int main(){


    // priority queue
    priority_queue<int> pq;     // max heap 
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "Top element: " << pq.top() << endl ;
    pq.pop();
    cout << "Top element: " << pq.top() << endl ;
    
    cout << "Size of the priority queue is: " << pq.size() << endl;

    if(pq.empty())
        cout << "The max heap is empty" << endl;
    else 
        cout << "The max heap is not empty" << endl;


    priority_queue< int, vector<int>, greater<int> > minHeap;       //syntax for min heap



    return 0;
}