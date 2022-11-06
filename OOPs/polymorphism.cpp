#include <iostream>
using namespace std;

class A{
    public:

    //funciton overloading
    void sayHello(){
        cout << "Hello aayush yadav" << endl;
    }

    //Error  - same function name with same signature
    // void sayHello(){
    //     cout << "Hello " << endl;
    // }

    //Functino overloading - same function name with different signature - works
    void sayHello(string name){
        cout << "Hello " << name << endl;
    }

    //Error - same funvtion name with different return type is not overloaded even with same signature
    // int sayHello(string name){
    //     cout << "Hello " << name << endl;
    //     return 1;
    // }

    //Works - same function name with different return type but with different signature
    int sayHello(string name, int n){
        cout << "Hello " << name << endl;
        return 1;
    }

};


int main(){

    A obj;
    obj.sayHello();
    obj.sayHello("Aayush");


    return 0;
}