#include <iostream>
using namespace std;

int main(){

    int num = 5;

    cout << num << endl; 

    //address of operator

    cout << "Address of num : " << &num << endl;

    //creating pointer

    int *ptr = &num;

    cout<< "Value is : "<< *ptr << endl;
    cout<< "Address is : "<< ptr << endl;


    double d = 5.4;
    double *p2 = &d;

    cout<< "Value is : "<< *p2 << endl;
    cout<< "Address is : "<< p2 << endl;


    cout << "Size of integer is: "<< sizeof(ptr)<<endl;
    cout << "Size of integer is: "<< sizeof(num)<<endl;
    cout << "Size of integer is: "<< sizeof(d)<<endl;
    cout << "Size of integer is: "<< sizeof(p2)<<endl;
    return 0;
}