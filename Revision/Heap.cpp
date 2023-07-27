#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Heap {
    public: 
        int arr[100];
        int size;

        Heap(){
            arr[0] = -1;
            size = 0;
        }


        void insertIntoHeap(int data){
            size = size + 1;
            arr[size] = data;
            int index = size;
            while(index > 1){
                int parentIndex = index/2;
                if(arr[parentIndex] < arr[index]){
                    swap(arr[parentIndex], arr[index]);
                    index = parentIndex;
                }
                else{
                    return ;
                }
            }
        }

        void deletionHeap() {
            arr[1] = arr[size];
            size--;
            int i =  1;

            while( i < size){
                int leftChild = 2*i;
                int rightChild = 2*i+1;

                if( leftChild < size &&  arr[i] < arr[leftChild]){
                    swap(arr[i], arr[leftChild]);
                    i = leftChild;
                }
                else if(rightChild < size && arr[i] < arr[rightChild]){
                    swap(arr[i], arr[rightChild]);
                    i = rightChild
                }
                else{
                    return;
                }
            }
        }

};
int main(){



    return 0;
}