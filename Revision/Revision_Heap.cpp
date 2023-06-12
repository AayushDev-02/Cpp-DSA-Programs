#include <iostream>
using namespace std;

class Heap{
    public: 
        int arr[101];
        int size;

        Heap(){
            size = 0;
        }

        void insert(int val){

            //step 1: insert value at end
            size=size+1;     // 0 pe insert nhi karte , we start from 1
            int index = size;
            arr[index] = val;

            //step 2: value ko sahi position pe le jao
            while(index > 1)        // 1 se chalu hota h so 1 aur 0 nhi le sakte because 0 to defined hi nhi h aur 1 liya to uska parent 0 aayega 
            {
                int parentIndex = index/2;
                if(arr[index] > arr[parentIndex]){
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else{
                    break;
                }
            }
        }

        void delete(){
            // we always delete the root node - top node
            // thus 
            //step 1: swap the last element and the root element ;
            arr[1] = arr[size];

            //step 2: delete the last node
            size--;

            //step 3: root ko uski sahi location pe le jao
            int index = 1;
            while(index < size){
                int left = 2*index;
                int right = 2*index+1;

                int largest = index;

                if(left < size && arr[largest] < arr[left]){
                    largest = left;
                }

                if(right < size && arr[largest] < arr[right]){
                    largest = right;
                }

                if(largest == index) {
                    //value is at correct position
                    break;
                }
                else{
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
                
            }


        }

};


int main(){

    Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    // h.size = 6;
    cout << "Printing the heap" << endl;
    for(int i=0; i<=h.size; i++){
        cout << h.arr[i] <<  " ";
    }

    cout << endl; 

    //inserting a new element 
    // h.insert(110);

    // for(int i=0; i<=h.size; i++){
    //     cout << h.arr[i] <<  " ";
    // }
    

    return 0;
}