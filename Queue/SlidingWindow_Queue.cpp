#include <iostream>
#include <deque>
using namespace std;


void solve(int arr[], int n, int k ){

    //step 1: create a dequeue
    deque<int> q;

    //step 2: process the first window
    for(int i=0; i<k; i++){
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    //process remaining window
    for(int i=k; i<n; i++){
        //first store/print the ans of first window
        if(q.empty()){
            cout << 0 <<  " ";
        }
        else{
            cout << arr[q.front()] << " ";
        }

        //remove the indexes from queue which are out of window
        while( (!q.empty()) && (i - q.front() >= k)){
            q.pop_front();
        }

        //check current element for insertion
        if(arr[i] < 0){
            q.push_back(i);
        }

    }
    
    // answer print karo last window ka
    if(q.empty()){
        cout << 0 << " ";
    }
    else{
        cout << arr[q.front()] << " "; 
    }
}

int main(){

    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int size = 8;

    int k = 3;

    solve(arr, size, k);



    return 0;
}