#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//using switch case
int signum(int a, int b){
    if( a == b ){
        return 0;
    }

    if(a < b){
        return 1;
    }

    if( a > b ){
        return -1;
    }
}

void callMedian2(int &median, priority_queue<int>& maxHeap, priority_queue<int,vector<int>, greater<int>> &minHeap, int element){

    switch(signum(maxHeap.size(), minHeap.size())){

        case 0:
            if(element > median){

                minHeap.push(element);
                median = minHeap.top();

            }
            else{
                maxHeap.push(element);
                median = maxHeap.top();
            }

            break;

        case 1:
            
            if(element > median){       // CASE 5 - part 1

                int topElement = minHeap.top();
                minHeap.pop();
                maxHeap.push(topElement);
                minHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2;

            }
            else{                       // CASE 6 - part 2
                maxHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2;
            }

            break;

        case -1:

            if(element > median){   // CASE 6 - part 1

                minHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2;

            }
            else{                   // CASE 6 - part 2
                int topElement = maxHeap.top();
                maxHeap.pop();
                minHeap.push(topElement);
                maxHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2;
            }

            break;

    }

}


// using if else 
void callMedian1(int &median, priority_queue<int>& maxHeap, priority_queue<int,vector<int>, greater<int>> &minHeap, int element){

    // 3 cases:

    //CASE 1
    if(maxHeap.size() == minHeap.size()){
        
        //compare element with median
        if(element > median){

            minHeap.push(element);
            median = minHeap.top();

        }
        else{
            maxHeap.push(element);
            median = maxHeap.top();
        }
    }
    //CASE 2
    else if(maxHeap.size() < minHeap.size()){

        if(element > median){       // CASE 5 - part 1

            int topElement = minHeap.top();
            minHeap.pop();
            maxHeap.push(topElement);
            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;

        }
        else{                       // CASE 6 - part 2
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }

    }

    //CASE 3
    else if(maxHeap.size() > minHeap.size()){
        if(element > median){   // CASE 6 - part 1

            minHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;

        }
        else{                   // CASE 6 - part 2
            int topElement = maxHeap.top();
            maxHeap.pop();
            minHeap.push(topElement);
            maxHeap.push(element);
            median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }

}


int main(){
    int arr[6] = {5,7,2,9,3,8};
    int n = 6;

    int median = 0;

    //max Heap
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;


    for(int i=0; i<n; i++){
        int element = arr[i];
        callMedian2(median, maxHeap, minHeap, element);
        cout << " --> " << median << " ";
    }
    return 0;
}