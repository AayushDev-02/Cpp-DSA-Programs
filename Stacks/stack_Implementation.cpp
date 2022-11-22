#include <iostream>
using namespace std;

// manual implementation of stack using array
class stack{
    
    //properties
    public:
        int *arr;
        int top;
        int size;
    
    //behaviour
    stack(int size){

        this->size = size;
        this->arr = new int[size];    // dynamically created array.
        top = -1;

    }

    void push(int element){

        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{

            cout << "Stack Overflow" << endl;

        }

    }

    void pop(){

        if(top >=0){
            top--;
        }
        else{
            cout << "Stack Underflow" << endl;
        }

    }

    int peek(){
        if(top >=0 ){
            return arr[top];
        }
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }

    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
};


int main(){

    //creation and passing the size into parametrised constructor
    stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);

    st.pop();

    cout << "Element at top: " << st.peek() << endl;

    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }else{
        cout << "Stack is not empty" << endl;
    }

    
    


    return 0;
}