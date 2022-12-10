#include <iostream>
using namespace std;

class circularQueue{
    int arr*;
    int size;
    int qfront;
    int rear;

public:
    circularQueue(int n){
        size = n;
        arr = new arr[size];
        qfront = -1;
        rear = -1;
    }


    bool enqueue(int value){
        
        if((qfront == 0 && rear == size -1) || (rear == (qfront-1)%(size - 1) )){
            cout << "Queue is full " << endl;
            return false;
        }
        else if(qfront == -1){      //first element to push

            qfront = 0;
            rear = 0;
        }
        else if(rear == size - 1 && qfront!=0){
            rear = 0;   //to maintain cyclic nature
        }
        else{           // normal flow
            rear++;
        }

        arr[rear] = value;          // push inside queue
        return true;


    }

    int dequeue(){

        
        
        // check for empty 
        if(qfront == -1){
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;

        // single element
        if(qfront == rear){
            qfront = rear = -1;
        }

        // last element
        else if(qfront == size-1){
            qfront = 0;      // to maintain cyclic nature
        }
        else{
            qfront++;       // normal flow
        }

        return ans;

    }

};




int main(){

}