#include <iostream>
using namespace std;

class doublyEndedQueue{
    int *arr;
    int size;
    int rear;
    int front;

    public:
    doublyEndedQueue(int n){
        size = n;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    bool push_front(int data){

        // full condition
        if( isFull()  ){
            return false;
        }
        else if(empty()){
            front = rear = 0;
        }
        else if(front == 0 && rear!=size-1){
            front = size-1;
        }
        else{
            front--;
        }

        arr[front] = data;
        return true;

    }

    void push_back(int data){
        if( isFull()  ){
            return false;
        }
        else if(empty()){
            front = rear = 0;
        }
        else if(rear == size-1 && front!=0){
            rear = 0;
        }
        else{
            rear++;
        }

        arr[rear] = data;
        return true;
    }

    int pop_front(){
        if(empty() ){
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // condition 1 : only one element is present
        if(front == rear){
            front = rear = -1; 
        }
        // condition 2: circular property
        else if( front == size -1 ){
            front = 0;
        }
        // condition 3: normal case
        else{
            front++;   
        }

        return ans;
    }

    int pop_back(){

        if(empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        // condition 1 : only one element is present
        if(front == rear){
            front = rear = -1; 
        }
        // condition 2: circular property
        else if( rear == 0 ){
            rear = size-1;
        }
        // condition 3: normal case
        else{
            rear--;   
        }

        return ans;
    }

    int getFront(){
        if(empty()){
            return -1;
        }

        return arr[front];
    }

    int getRear(){
        if(empty()){
            return -1;
        }

        return arr[rear];
    }

    bool empty(){
        if(front == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if( (rear == size-1 && front == 0) || ( front!=0 && rear == (front-1) % (size - 1))  ){
            return true;
        }else{
            return false;
        }
    }


};


int main(){

}