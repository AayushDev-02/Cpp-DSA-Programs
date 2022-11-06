#include <iostream>
using namespace std;

void insertionSort(int *arr, int n){

    //first element is considered sorted
    //n-1 rounds
    for(int i=1; i< n; i++){

        int temp = arr[i]; 
        int j = i-1;
        for( ; j>=0 ; j--){

            if( temp < arr[j]){
                // shift
                arr[j+1] = arr[j];
            }
            else{
                //rukjao
                break;
            }
        }

        arr[j+1] = temp;

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

    int n = 7;

    int arr[n] = {10,1,7,4,8,2,11};

    insertionSort2(arr, n);

    for(int i=0; i< n; i++ ){

        cout << arr[i] << " ";

    }

    return 0;
}