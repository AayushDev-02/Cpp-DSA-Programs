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
};


int main(){

    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;

    h.size = 5;
    cout << "Printing the heap" << endl;
    for(int i=0; i<=h.size; i++){
        cout << h.arr[i] <<  " ";
    }

    cout << endl; 

    //inserting a new element 
    h.insert(110);

    for(int i=0; i<=h.size; i++){
        cout << h.arr[i] <<  " ";
    }
    

    return 0;
}