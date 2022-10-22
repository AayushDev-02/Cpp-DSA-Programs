#include <iostream> 
using namespace std;

void print( int arr[], int n, int start = 0 /*Default Argument */ ){

    for( int i = start ; i<n ; i++ ){
        cout << arr[i] << endl;
    }
}

int main(){

    int arr[5] = {1,4,7,8,9};
    int size = 5;

    print(arr,size);  // calling func print without start argument
    cout << endl;
    print( arr , size , 2 );  // calling func print with start argument



    return 0;
}