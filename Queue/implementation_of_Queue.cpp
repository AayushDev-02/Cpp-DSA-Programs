#include <iostream>
using namespace std;
 
class queue{

public:
    int* arr;
    int size = 1000;
    int front;
    int rear;

    queue(int n){
        this->size = n;
        arr = new int[this->size];
        front = 0;
        rear = 0;   
    }

    // Push operation
    void push(int element){

        // check if array is full
        if(rear == size){
            cout << "Queue is full " << endl;
        }
        else{

            arr[rear] = element;
            rear++;

        }

    }

    // Pop operation 
    void pop(){

        // check if array / queue is empty
        if(front == rear) {
            cout << "Array is empty" << endl;
        }
        else{
            arr[front] = -1;    // if we assume the empty location as -1
            front++;

            // to prevent wastage of memory in array
            if(front == rear){
                front == 0;
                rear == 0;
            }
        }

    }

    // check if queue is empty or not
    bool Empty(){
        if(front == rear) {
            return true;
        }else{
            return false;
        }
    }

    // front element in queue
    int Front(){
        if(front == rear) {
            return -1;
        }
        
        return arr[front];
    }


};


int main(){

    queue obj(5);
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);

    cout << "Size of the queue is: " << obj.size << endl;

    cout << "Front of the queue is : " << obj.Front() << endl;

    obj.pop();
    cout << "Size of the queue is: " << obj.size << endl;

    cout << "Front of the queue is : " << obj.Front() << endl;

    if(obj.Empty()){
        cout << "Queue is empty! " << endl;
    }
    else{
        cout << "Queue is not empty! " << endl;

    }






    return 0;
}