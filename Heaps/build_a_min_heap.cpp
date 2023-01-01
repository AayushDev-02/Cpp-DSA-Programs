#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int size, int index){
    int smallest = index;
    int leftChild = 2*index + 1; // zero base indexing
    int rightChild = 2*index + 2;    // zero base indexing
    
    if(leftChild < size && arr[smallest] > arr[leftChild]){
        smallest = leftChild;
    }
    
    if(rightChild < size && arr[smallest] > arr[rightChild]){
        smallest = rightChild;
    }
    
    if(smallest != index){
        swap(arr[smallest], arr[index]);
        heapify(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2 - 1 ; i>=0; i--){
        heapify(arr, n, i);
    }
    
    return arr;
}
