#include <iostream>
using namespace std;

void selectionSort(int* arr, int size){

    if(size == 0 || size == 1){
        return;
    }

    int min= INT_MAX;
    int minIndex = 0;

    for(int i= 0; i<size ; i++){
        if(arr[i] < min){
            minIndex = i;
            min = arr[i];
        }
        swap(arr[0], arr[minIndex]);
    }

    return selectionSort(arr+1,size-1);
}

int main(){

    int n;
    cout << "Enter size :";
    cin >> n;

    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted Array : ";

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}