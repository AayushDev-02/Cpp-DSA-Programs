#include <iostream>
#include <queue>

using namespace std;

int main(){

    cout << "Max Heap : " << endl << endl;

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

    cout << endl;

    cout << "Min Heap" << endl << endl;

    priority_queue< int, vector<int>, greater<int> > minHeap;       //syntax for min heap

    minHeap.push(3);
    minHeap.push(6);
    minHeap.push(9);
    minHeap.push(4);
    minHeap.push(8);

    cout << "Top element: " << minHeap.top() << endl ;
    cout << "Size of the priority queue is: " << minHeap.size() << endl;
    minHeap.pop();
    cout << "Top element: " << minHeap.top() << endl ;
    cout << "Size of the priority queue is: " << minHeap.size() << endl;

    if(minHeap.empty())
        cout << "The max heap is empty" << endl;
    else 
        cout << "The max heap is not empty" << endl;

    return 0;
}