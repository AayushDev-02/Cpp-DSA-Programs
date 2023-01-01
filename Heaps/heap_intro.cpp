#include <iostream>
using namespace std;

class Heap {
    public:
        int arr[100];
        int size;

        // Constructor
        Heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){                       // TC - O(log N)

            // put the element at end
            size = size+1;
            int index = size; 
            arr[index] = val;

            // move the element to its correct position 
            while(index > 1){
                int parent = index/2;
                
                // MAX HEAP Condition
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
                

                // MIN HEAP Condition
                /*
                if(arr[parent] > arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }else{
                    return;
                }
                */
            }
        }

        // Print function
        void print(){

            // since we do not insert anything at the 0th index - we start iteration from 1st index

            for(int i=1; i<=size ; i++){
                cout << arr[i] << " ";
            }cout << endl;
        }

        void deleteFromHeap(){                  // TC - O(log N)

            // if heap is already empty
            if(size == 0){
                cout << "Nothing to delete" << endl;
                return;
            }
            // step 1 - put last node into first node
            arr[1] = arr[size];

            // Step 2 - Remove last element -- decrement size
            size--;

            //Step 3- take root node to its correct position
            int i=1;
            while(i<size){
                int leftChild = 2*i;        // formula for left child index
                int rightChild = 2*i+1;     // formula for right child index

                if(leftChild < size && arr[i] < arr[leftChild]){                // check max heap condition with left child
                    swap(arr[i], arr[leftChild]);                           
                    i = leftChild;
                }
                else if(rightChild < size && arr[i] < arr[rightChild]){         // check max heap condition with right child
                    swap(arr[i], arr[rightChild]);
                    i = rightChild;
                }
                else{
                    return;
                }
            }
        }
};

int main(){

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();


    return 0;
}