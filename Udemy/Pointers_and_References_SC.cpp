#include <iostream>
using namespace std;

void print(int *arr, int size){

    for(int i=0; i< size ; i++){
        cout << arr[i] << " ";
    }

}

int* apply_all(int *arr1, int size1, int *arr2, int size2){

    int* final = new int[size1*size2];

   
    int k=0;
    for(int i=0; i< size2; i++){
        for(int j=0; j< size1 ;j++){
           final[k] = arr2[i]*arr1[j];
           k++; 
        }
    }

    return final;

}


int main(){

    int size1 = 5;
    int arr1[size1] = {1,2,3,4,5};
    
    int size2 = 3;
    int arr2[size2] = {10,20,30};

    cout << "Array 1 :" ;
    cout << " [ ";
    print(arr1,size1);
    cout << " ] ";
    
    cout << endl;

    cout << "Array 2 :" ;
    cout << " [ ";
    print(arr2,size2);
    cout << " ] ";

    cout << endl;

    int *result = apply_all(arr1, size1, arr2, size2);
    cout << "Result :";
    cout << " [ ";
    print(result,size1*size2);
    cout << " ] ";

    cout << endl;

    delete [] result;
    cout << endl;
    return 0;
}