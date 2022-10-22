#include <iostream>
using namespace std;


int Peak(int arr[],int size){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    int ans;
    while(s<=e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }else if(arr[mid]>arr[mid+1]){
            e=mid-1;
        }
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            ans=mid;
        }

        mid=s+(e-s)/2;
    }
    return ans;
}


int main(){
    int arr[7]={0,1,2,3,4,3,0};
    int ans=Peak(arr,7);
    cout<<"Peak is at index: "<<ans;
    return 0;
}