#include <iostream>
using namespace std;

int getSum(int *arr, int n){

    int sum = 0;
    for(int i =0 ; i < n; i++){
        sum += arr[i];
    }
    return sum;
}


int main(){

    // char ch = 'q';
    // cout << "Size of character :" << sizeof(ch) << endl;         

    // char *c = &ch;
    // cout << "Size of poiner : " << sizeof(c) << endl;

    int n ;
    cout << "Enter size : ";
    cin >> n;

    //creating variable size array
    int* arr = new int[n];

    //taking inpur in arry
    for(int i =0; i<n;i++ ){
        cin >> arr[i];
    }

    int ans = getSum(arr, n);
    cout << "Sum of variable size array : " << ans << endl;




    return 0;
}