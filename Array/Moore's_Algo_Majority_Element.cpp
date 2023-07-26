#include <iostream>
#include <vector>
using namespace std;



int majorityElement(vector<int> arr){

    int element = 0;
    int count = 0;

    for(int i=0; i<arr.size(); i++){
        if(count == 0){
            element = arr[i];
        }

        if(element == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }

    //check if element after calc is majority or not

    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == element){
            cnt++;
        }
    }


    if(cnt > arr.size()/2){
        return element;
    }

    return -1;

}


int main(){

    vector<int> arr{2,2,1,1,1,2,2};
    int ans = majorityElement(arr);
    cout << "Majority Element :" << ans;

    return 0;
}