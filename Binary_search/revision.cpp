#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int BinarySearch(int arr[], int size, int target) {

    int start = 0;
    int end = size-1;

    int mid = start+(end-start)/2;

    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            start = mid+1;
        }
        else{
            end = mid - 1;
        }

        mid = start+(end-start)/2;
        

    }

    return -1;

}

 


int main(){

    int arr[] = {1,2,4,5,8,10};
    int size = 6;

    int target = 4;

    int indexAns = BinarySearch(arr,size,  target);

    if(indexAns == -1){
        cout << "Element not found!" << endl;
    }
    else{
        cout << "Element present at the index : " << indexAns << endl;
    }

    vector<int> v{1,2,3,4,5,6,7};
    int arr2[] = {1,2,3,4,5,6,7};
    int size2 = 7;
    if(binary_search(v.begin(), v.end(), 5)){
        cout <<  "Found" << endl;
    }
    else{
        cout <<  "Not Found" << endl;

    }

    if(binary_search(arr, arr + size2, 5)){
        cout <<  "Found" << endl;
    }
    else{
        cout <<  "Not Found" << endl;

    }
     

    return 0;
}