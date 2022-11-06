#include <iostream>
using namespace std;

void Insertion_sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int temp = arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}


void insertionSort2(int *arr, int n){

    //using while
    int i = 1;
    while(i<n){
        
        int temp = arr[i];
        int j = i-1;

        while(j>=0){

            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }

            j--;

        }

        arr[j+1] = temp;

        i++;
    }
}



int main(){

    int arr[4]={1,4,2,3};
    Insertion_sort(arr,4);

    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}