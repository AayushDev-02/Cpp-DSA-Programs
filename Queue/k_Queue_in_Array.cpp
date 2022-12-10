#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class kQueue{
    public:
    
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

    kQueue(int n, int k){

        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];

        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];

        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];

        freeSpot = 0;

    }


    void enqueue(int data, int qn){

        //overflow condition
        if(freeSpot == -1){
            cout << "No empty space is present" << endl;
            return;
        }

        //find first free index
        int index = freeSpot;

        //update free spot
        freeSpot = next[index];

        // first element condition - check whether first element
        if(front[qn - 1] == -1){            // qn - 1 because it is 0 based indexing 
            front[qn - 1] = index;
        }
        else{
            // to maintain link in the elements of respective queue using next array
            next[rear[qn - 1]] = index;
        }

        // update the next pointer in next array as no space is available at index - set it to -1
        next[index] = -1;

        // update the rear pointer of the perticular queue
        rear[qn - 1] = index;

        // Push element
        arr[index] = data;  

    }


    int dequeue(int qn){

        // check under flow condition - queue is empty
        if(front[qn-1] == -1){
            cout << "Queue is empty - underflow condition" << endl;
            return -1;
        }

        // find index
        int index = front[qn-1];

        // front ko aage badhao
        front[qn - 1] = next[index];

        // manage free spot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }



};


int main(){

    kQueue q(10,3);

    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    // cout << q.dequeue(1) << endl;

    return 0;
}