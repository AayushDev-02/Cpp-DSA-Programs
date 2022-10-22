#include <iostream>
using namespace std;

int main(){

    // while(true){
    //     int* i = new int;
    // }

    // Void Pointer
    int i = 5;
    void *ptr = &i;

    cout << "Address of i :" << &i << endl;
    cout << "Address of i using void pointer :" << ptr << endl;
    cout << endl;

    cout << "Value of i : " << i << endl;
    cout << "Value of i using void pointer : " << *ptr << endl; // ERROR - we cannot dereference a void pointer
    cout << endl;


    return 0;
}