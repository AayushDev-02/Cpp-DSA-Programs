#include <iostream>
using namespace std;

// HEAPIFY FUNCTION ------------------------------------------------------------------------------------------------------------------------------------
void heapify(int arr[], int size, int index){
    
    int largest = index;
    int leftChild = 2*index;
    int rightChild = 2*index+1;

    if(leftChild <= size && arr[largest] < arr[leftChild]){     //since it is 1 based indexing we need >= in bound check
        largest = leftChild; 
    }

    if(rightChild <= size && arr[largest] < arr[rightChild]){   //since it is 1 based indexing we need >= in bound check
        largest = rightChild;
    }

    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }

}

void heapSort(int arr[], int n){
   int size = n;

   while(size>1){
    //step 1: swap first node to last node
    swap(arr[size], arr[1]);
    //decrement size
    size--;
    //step 2: place at correct position
    heapify(arr, size, 1);
   } 
}


int main(){

    int arr[6] = {-1,54,53,55,52,50};

    int size = 5;          // above array - CBT has 5 nodes
    for(int i= size/2; i>0; i-- ){
        heapify(arr, size, i);
    }

    // sorting the heap
    heapSort(arr, size);

    cout << "Printing the sorted array: " << endl;
    for(int i=1; i<=size; i++){
        cout << arr[i] << " ";
    }cout << endl;

}