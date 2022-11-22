#include <iostream>
using namespace std;

int partition(int *arr, int start, int end){

    int pivot = start;
    int val = arr[pivot];

    int i = start+1;
    int count=0;
    
    while(i<=end){

        if(arr[i] <= val ){
            count++;
        }

        i++;
    }

    //place pivot at right position
    swap(arr[pivot], arr[start+count] );
    pivot = start+count;

    i= start;
    int j= end;

    while(i<pivot && j>pivot){

        while(arr[i] < val){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(arr[i] > val && arr[j] < val){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivot;


}





void quickSort(int arr[], int start, int end){

    //base case
    if(start >= end){
        return;
    }

    // partition and get correct position of element
    int p = partition(arr, start, end);

    // recursive relation - will sort the left and right part recursively
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);

}




int main(){

    int n = 5;
    int arr[] = {2,4,1,6,9};

    int start = 0;
    int end = n-1;

    quickSort(arr, start, end);

    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}