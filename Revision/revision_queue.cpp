#include <iostream>
#include <stack>
#include <queue>
using namespace std;


//  ----------------------------------------------------------------------- Standard Queue ------------------------------------------------------
// class queue{
//     int *arr;
//     int size;
//     int rear;
//     int front;

//     public:
//     queue(int n){
//         size = n;
//         arr = new int[size];
//         rear = 0;
//         front = 0;
//     }

//     void enqueue(int data){

//         //check full condition
//         if(rear == size){
//             cout << "Queue is full " << endl;
//         }else{

//             arr[rear] = data;
//             rear++;
//         }


//     }

//     int dequeu(){
//         //check empty condition
//         if(front == rear){
//             cout << "Queue is empty" << endl;
//             return -1;
//         }else{
//             int x = arr[front];
//             arr[front] = -1;
//             front++;

//             if(front == rear){
//                 front = rear = 0;
//             }   

//             return x;
//         }
//     }

//     bool empty(){
//         if(rear == front){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     int frontElement(){
//         if(front == rear){
//             return -1;
//         }else{
//             return arr[front];
//         }
//     }


// };


// int main(){

//     queue q1(5);
//     q1.enqueue(1);
//     q1.enqueue(2);
//     q1.enqueue(3);
//     q1.enqueue(4);
//     q1.enqueue(5);

//     // while(!q1.empty()){
//     //     cout << q1.frontElement() << " ";
//     //     q1.dequeu();
        
//     // }
//     cout << endl;

//     cout << q1.dequeu() << endl;

//     return 0;
// }




//  ----------------------------------------------------------------------- Standard Queue ------------------------------------------------------





//  ----------------------------------------------------------------------- Circular Queue ------------------------------------------------------

// class circularQueue{
//     int *arr;
//     int size;
//     int rear;
//     int front;

//     public:
//     // CONSTRUCTOR
//     circularQueue(int n){

//         size = n;
//         arr = new int[size];
//         rear = -1;
//         front = -1;

//     }

//     void enqueue(int data){
//         // check full condition and the condition of rear is before front
//         if( (rear == size-1 && front == 0) || (rear == (front-1) % (size - 1))  ){
//             cout << "Queue is full , cannot insert element" << endl;
//         }

//         // first condition - if we are inserting the first element
//         else if(front == -1 ){
//             front = rear = 0;
//             arr[rear] = data;
//         }
//         // second condition - if rear is at the end of the array - thus applying property of circular queue
//         else if(rear == size-1 && front!=0){
//             rear = 0;
//         }
//         // third condition - normal case of insertion
//         else{
//             rear++;
//         }

//         arr[rear] = data;

//     }

//     int dequeue(){

//         // check if queue is empty
//         if(front == -1 ){
//             cout << "Queue is empty" << endl;
//             return -1;
//         }

//         int ans = arr[front];
//         arr[front] = -1;

//         // condition 1 : only one element is present
//         if(front == rear){
//             front = rear = -1; 
//         }
//         // condition 2: circular property
//         else if( front == size -1 ){
//             front = 0;
//         }
//         // condition 3: normal case
//         else{
//             front++;   
//         }

//         return ans;

//     }

//     bool empty(){
//         if(front == -1){
//             // cout << "Queue is empty";
//             return true;
//         }else{
//             return false;
//         }


//     }

//     int frontElement(){
//         return arr[front];
//     }

// };

// int main(){

//     circularQueue q1(5);
//     // q1.empty();
//     cout << endl;
    
//     q1.enqueue(5);
//     q1.enqueue(4);
//     q1.enqueue(3);
//     q1.enqueue(2);
//     q1.enqueue(1);
//     cout << q1.dequeue() << endl;
//     q1.enqueue(-1);

//     while(!q1.empty()){{
//         cout << q1.frontElement() << " " ;
//         q1.dequeue();
//     }}



//     return 0;
// }






//  ----------------------------------------------------------------------- Circular Queue ------------------------------------------------------

//  ----------------------------------------------------------------------- Doubly ended Queue ------------------------------------------------------


// class doublyEndedQueue{
//     int *arr;
//     int size;
//     int rear;
//     int front;

//     public:
//     doublyEndedQueue(int n){
//         size = n;
//         arr = new int[size];
//         rear = -1;
//         front = -1;
//     }

//     void push_front(int data){

//     }

//     void push_back(int data){

//     }

//     int pop_front(){

//     }

//     int pop_back(){

//     }
// };


//  ----------------------------------------------------------------------- Doubly ended Queue ------------------------------------------------------



//  ----------------------------------------------------------------------- Reverse a Queue ------------------------------------------------------


// void solve(queue<int> &q, queue<int> &ans ){
//     if(q.empty()){
//         return;
//     }

//     int x = q.front();
//     q.pop();
//     solve(q,ans);

//     ans.push(x);
// }


// queue<int> rev(queue<int> q){

    // method 1 : using stack
    // stack<int> s;

    // while(!q.empty()){
    //     s.push(q.front());
    //     q.pop();
    // }

    // while(!s.empty()){
    //     q.push(s.top());
    //     s.pop();
    // }
    
    // return q;
// ---------------------------------------

    // Method 2: using recursion

    // queue<int> ans;
    // solve(q,ans);
    // return ans;

// }

//  ----------------------------------------------------------------------- Reverse a Queue ------------------------------------------------------




















