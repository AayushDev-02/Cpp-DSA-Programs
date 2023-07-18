#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//implementing queue
class Queue {
public:
    int *arr;
    int size;
    int front;
    int rear ;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){

        //check if queue is full
        if(rear == size){
            cout << "Queue is full " << endl;
        }
        else{

            arr[rear] = data;
            rear = rear + 1;
        }

    }

    void popFront(){
        //check if queue is empty
        if(front == rear){
            cout <<"Queue is empty" << endl;
        }
        else{

            arr[front] = -1;
            front = front + 1;

            if(front == rear){
                front = 0;
                rear = 0;
            }

        }
    }

    int getFront() {
        //check if queue is empty
        if(front == rear) {
            cout << "Qeueu is empty " << endl;
            return -1;
        }
        else{
            // cout << arr[front] << endl;
            return arr[front];
        }
    }


    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        return rear - front;
    }
};

class CircularQueue {
    public :
        int *arr;
        int size;
        int front;
        int rear;

        CircularQueue(int size){
            this->size = size;
            arr= new int[size];
            front= -1;
            rear = -1;
        }

        void push(int data){
            //check if queue is full
            if((front == 0 && rear == size-1) || (rear = front-1)){
                cout << "QUEUE IS FULL , CANNOT INSERT" << endl;
            }
            else if(front == -1){
                front = rear = 0;
                arr[front] = data;
            }
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = data;
            }
            else{
                rear++;
                arr[rear] = data;
            }
        }

        void pop(){
            //check if queue is empty
            if(front == -1 ){
                cout << "Queue is empty";
            }
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }

            else if(front == size-1){
                arr[front] = -1;
                front = 0;
            }
            else{
                arr[front] = -1;
                front += 1;
            }
        }     
};

class Dequeue {
    public: 
        int arr*;
        int size;
        int front;
        int rear;

        Dequeue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void pushRear(int data){
            if((front == 0 && rear == size-1) || (rear == front-1)){
                cout << "Queue is full" << endl;
                return;
            }
            else if(front == -1){
                front = 0;
                rear = 0;
                
            }else if(rear = size-1 && front != 0){
                rear = 0;
                
            }
            else{
                rear = rear+1;
            }
            arr[rear] = data;
        }

        void pushFront(int data) {

            if((front == 0 && rear == size - 1) && (rear == front - 1) ){
                cout << "Queue is full " << endl;
                return;
            }
            else if(front == -1){
                front = rear = 0;
            }
            else if(front == 0 && rear != size - 1){
                front = size - 1;
            }
            else {
                front = front - 1;
            }

            arr[front] = data;
        }

        void popFront(){

            if(front == -1 ){
                cout << "Queue is Empty" << endl;
                
            }
            else if(front == rear){
                arr[front] = -1;
                front = rear = -1;
            }
            else if(front == size - 1 ){
                arr[front] = -1;
                front = 0;
            }
            else{
                arr[front] = -1;
                front = front + 1;
            }

        }

        void popRear(){
            if(rear == -1){
                cout << "Queue is empty " << endl;
            }
            else if(front == rear){
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }
            else if(rear == 0){
                arr[rear] = -1;
                rear = size - 1;
            }
            else {
                arr[rear] = -1;
                rear = rear - 1 ;
            }
        }
}

int gasStation (vector<int> &gas, vector<int> &costs){

    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i=0; i<gas.size(); i++){

        balance = balance + gas[i];
        int distance = costs[i];
        balance = balance - distance;

        if(balance > 0){
            deficit += balance;
            balance = 0;
            start = 0;
        }

    }

    if(balance + deficit >= 0){
        return start;
    }

    return -1;

}


int main(){
    // //STL
    // queue<int> q;

    // //insertion 
    // q.push(5);
    // q.push(15);
    // q.push(25);
    // q.push(55);

    // cout << "Size: " << q.size() << endl;

    // //popping
    // q.pop();
    // cout << "Size: " << q.size() << endl;

    // //printing
    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    // cout << endl; 

    // if(q.empty()){
    //     cout << "Queue is empty" << endl;
    // }

    //Queue Implementation
    Queue q(5);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);

    cout << q.size << endl;

    while(!q.isEmpty()){
        cout << q.getFront() << " ";
        q.popFront();
    }

    cout << endl;

    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }


    return 0;
}