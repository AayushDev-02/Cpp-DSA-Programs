#include <iostream>
using namespace std;

void alternateSwap(int array[],int size){

    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(array[i],array[i+1]);
        }
    }


    return;
}

int main(){

    int array[6]={1,2,7,8,5,11};

    alternateSwap(array,6);

    for(int i=0;i<6;i++){
        cout<<array[i]<<" ";
    }

    return 0;
}