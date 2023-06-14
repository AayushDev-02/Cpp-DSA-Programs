#include <iostream>
#include<queue>
using namespace std;


//custom variable
class minHeap{
    public:
        int data;
        int row;    // the index of which list/array we are referring to
        int col; // the elements in a list/array
        
        info(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }

};

class compare{
    public: 
        bool operator()(info* a, info* b){
            return a->data > b->data;
        }
};


//input type - [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
vector<int> smallestRange(vector<vector<int>>& nums){

    //create a min Heap - we are using min heap because the range of a array can only be reduced by reducing the max or increasing the min value , but since we are given the sorted list we can only move right thus we can only increase min value therefore --> min heap is used

    priority_queue<info*, vector<info*>, compare> minHeap;

    int mini = INT_MAX;
    int maxi = INT_MIN;

    // insert the first element of all the lists/arrays into the min heap
    int k = nums.size();
    for(int i=0; i<k; i++){
        info* newNode = new info(nums[i][0], i, 0);
        minHeap.push(newNode);

        mini = min(mini, nums[i][0]);
        maxi = max(maxi, nums[i][0]);
    }

    // now we store the the final minrange which will be updated during the inserting of new elements
    //this is the default range elements after inserting the first n element;
    int ansStart = mini;
    int ansEnd = maxi;

    while(!minHeap.empty()){
        info* topNode = minHeap.top();  // this will be the minimum value of all the elements added
        topNode.pop();

        int value = topNode->data;
        int row = topNode->row;
        int index = topNode->col;

        //we need to update the mini
        mini = value;

        //check if the new range is smaller than the prev range
        int prevRange = ansEnd - ansStart;
        int currRange = maxi - mini;

        if(currRange < prevRange){
            ansStart = mini;
            ansEnd = maxi;
        }

        //now we insert the new element in the same array/list into the heap
        if(index + 1 < nums[row].size()){
            info* newNode = new info(nums[row][index+1], row, index+1);
            minHeap.push(newNode);
            //since we are adding a greater value we need to update the maxi
            maxi = max(maxi, nums[row][index+1]);
        }
        else{
            break;
        }
    }

    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);

    return ans;

}

int main(){
    return 0;
}





















