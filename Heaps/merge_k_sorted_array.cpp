#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class info {        // data we want to store into heap
    public: 
        int data;    // the value of element in the array
        int row;    // the value of row in array ( like - which array part is this element)
        int col;    // the col in the array (like - the index of element in the array)

        info(int val, int r, int c){
            data = val;
            row = r;
            col = c;
        }
};

// our custom comparator
class compare{
    public:
        bool operator()(info* a, info* b){
            return a->data > b->data;
        }
        
};

vector<int> mergeKSortedArray(int arr[][4], int k, int n){
    // create a min heap - custom heap of info type
    priority_queue< info*, vector<info*>, compare > minHeap;    
    //when we define a custom login of minheap in priority queue, we need to define a comparator

    // har array ke first element ko insert karo
    for(int i=0; i<k; i++){
        info* temp = new info(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    //create a ans vector;
    vector<int> ans;

    //insert the top element of heap into ans -> pop the heap -> increment the index and repeat until the heap is empty
    while(!minHeap.empty()){
        
        info* topElement = minHeap.top();
        minHeap.pop();

        int value = topElement->data;
        int row = topElement->row;
        int index = topElement->col;

        ans.push_back(value);
        
        //check if next index exist in the array 
        if(index + 1 < n){
            info* newInfo = new info(arr[row][index+1], row, index+1);
            minHeap.push(newInfo);
        }
    }

    return ans;
}

int main(){
    int arr[][4] = {{2,4,6,8}, {1,3,5,7}, {0,9,10,11}};
    int k = 3;
    int n = 4;

    vector<int> ans = mergeKSortedArray(arr, k, n);

    cout << endl; 

    //printing ans
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
