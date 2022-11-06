#include <iostream>
using namespace std;


class A{
    public:
    void func1(){
        cout << "Inside functino 1" << endl;
    }
};

class B: public A{

    public:
    void func2(){
        cout << "Inside function 2" << endl;
    }

};

class C: public A{

    public:
    void func3(){
        cout << "Inside function 3" << endl;
    }

};


int main(){

    A obj1;
    obj1.func1();
    cout << endl;

    B obj2;
    obj2.func1();
    obj2.func2();
    cout << endl;

    C obj3;
    obj3.func1();
    obj3.func3();
    cout << endl;

    //error as b and c are not connected/ inherited
    // obj3.func2();

    return 0;
}