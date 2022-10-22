#include <iostream>
using namespace std;

int main(){
    
    int dost[5];

    for(int i=0;i<5;i++){
        dost[i]=1;
    }

    cout<<"Value is: "<<dost[3]<<endl;
    cout<<"Size of array: "<<sizeof(dost)/sizeof(int);
    return 0;
}