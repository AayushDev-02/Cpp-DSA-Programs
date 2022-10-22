#include <iostream>
using namespace std;

bool isSorted_Recursion(int arr[] /* or int *arr */ , int size){

    // Base case
    if(size == 0 || size == 1){
        return true;
    }

    // Processing
    if(arr[0] > arr[1]){
        return false;
    }else{
        // Recursive Relation
        return isSorted_Recursion((arr+1), size - 1);
    }


}


int main(){

    int arr[5];

    for(int i= 0 ; i< 5 ; i++){
        cin >>arr[i];
    }

    cout << endl;;

    for(int i= 0 ; i< 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    bool ans = isSorted_Recursion(arr, 5);

    if(ans){
        cout << "Array is sorted " << endl;
    }else{
        cout << "Array is not sorted " << endl;

    }

    

    


    return 0;
}