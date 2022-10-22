#include <iostream>
using namespace std;

int findSum(int *arr, int size){

    //Base case
    if(size == 0){
        return 0;
    }
    if(size == 1 ){
        return arr[0];
    }
    // Recursive Relation
    return arr[0] + findSum(arr + 1, size -1);

}


int main(){

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter values in array: ";
    for(int i= 0 ; i< n ; i++){
        cin >>arr[i];
    }

    cout << endl;;

    for(int i= 0 ; i< n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int ans = findSum(arr, n);

    cout << "Sum of elements in array is : " << ans << endl;
    return 0;
}