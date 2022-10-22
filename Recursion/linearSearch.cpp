#include <iostream>
using namespace std;

bool findKey(int *arr, int size, int key){

    if(size == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }else{
        return findKey(arr+1 , size - 1, key);
    }


}




int main(){

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n]; //dynamic array

    cout << "Enter values : ";
    for(int i=0; i < n ; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter key value : ";
    cin >> key;

    bool ans = findKey(arr, n , key);
    cout << endl;

    if(ans){
        cout << "Key is present in the array" << endl;
    }else{
        cout << "Key is not present in the array" << endl;

    }

    return 0;
}