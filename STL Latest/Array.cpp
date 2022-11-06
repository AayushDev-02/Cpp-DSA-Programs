//STL Array

// Access elements :

// 1.   at()
// 2.   []
// 3.   front()
// 4.   back()
// 4.   data() -- gives access to the underlying array by returning the pointer to that array

#include <iostream>
#include <array>

using namespace std;

int main(){

    int basic[3] = {0,1,2};

    //creating a stl array
    array<int, 4> a = {0,1,2};
    array<int, 5> b = {1,2,3,4,5};  // initializer list
    array<int, 5> c {1,2,3,4,5};     // uniform intialization

    // assigning using initializer list
    array<int , 5> d;

    cout << a.at(0) << endl;
    cout << a.at(1) << endl;
    cout << a.at(2) << endl;

    cout <<"Size: " <<  a.size() << endl;



}
