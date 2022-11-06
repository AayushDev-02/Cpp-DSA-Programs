#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n){

    bool swapped= false;

    //for 1 to n-1 rounds
    for(int i=1 ; i<n ; i++){

        for(int j=0; j< n-i; j++  ){

            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }

        }

        if(swapped == false){
            //already sorted
            break;
        }



    }

}


int main(){

    int n = 6;
    int arr[n] = {10,1,7,6,14,9};

    bubbleSort(arr, n);

    for(int i=0; i< n; i++ ){

        cout << arr[i] << " ";

    }

    cout << endl;
    return 0;
}