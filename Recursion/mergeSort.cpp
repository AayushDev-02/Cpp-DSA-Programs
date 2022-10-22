#include <iostream>
using namespace std;

void merge(int *arr, int start, int end){

    int mid = start + (end-start)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copying values
    int k = start;
    for(int i=0;i< len1; i++){
        first[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0;i< len2; i++){
        second[i] = arr[k++];
    }


    //merge

    int index1 = 0;
    int index2 = 0;

    int mainArrayIndex = start;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex] = first[index1++];
        }else{
            arr[mainArrayIndex] = second[index1++];

        }
    }

    while(index1 < len1){
        arr[mainArrayIndex] = first[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex] = second[index2++];
    }
}

void MergeSort(int* arr, int start, int end){

    //base case
    if(start >= end){
        return;
    }

    int mid = start + (end-start)/2;

    //left part sort karna h
    MergeSort(arr,start,mid);
    MergeSort(arr, mid+1, end);

    merge(arr,start,end);
}

intmain(){

    int n;
    cout << "Enter size :";
    cin >> n;

    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int start = 0;
    int end = n-1;

    MergeSort(arr, start , end);

    cout << "Sorted Array : ";

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}