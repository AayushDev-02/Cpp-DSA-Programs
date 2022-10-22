#include <iostream>
using namespace std;

bool binarySearch(int *arr , int key, int start, int end){

    //base case
    if(start > end){
        return false;
    }
    
    
    //processing
    int mid = start+(end - start)/2;
    
    //recursive relation
    if(arr[mid] == key){
        return true;
    }else if(arr[mid] > key){
        return binarySearch(arr, key, start ,mid-1);
    }else{
        return binarySearch(arr, key, mid+1 ,end);
    }
}




int main(){

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n]; //dynamic array

    cout << "Enter values in sorted manner : ";
    for(int i=0; i < n ; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter key value : ";
    cin >> key;

    int start = 0;
    int end = n-1;

    bool ans = binarySearch(arr, key, start, end);
    cout << endl;

    if(ans){
        cout << "Key is present in the array" << endl;
    }else{
        cout << "Key is not present in the array" << endl;
    }



    return 0;
}