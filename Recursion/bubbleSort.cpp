#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size){

    //base case - already sorted
    if(size == 0 || size == 1){
        return;
    }

    //1 case solve karliya - largest element ko end me rakh dega
    for(int i=0;i<size-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    return bubbleSort(arr,size-1);


}



int main(){


    int n;
    cout << "Enter size :";
    cin >> n;

    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted Array : ";

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    

    return 0;
}