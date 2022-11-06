#include <iostream>
using namespace std;

class B{
    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

    //operator overloading -- + to substract

    void operator+ (B &obj){

        int value1 = this->a;
        int value2 = obj.a;

        cout << " Output : "<< value2 - value1 << endl;

        //OR
        // cout << "Aayush Yadav" << endl;
    }

    void operator() (){
        cout << "Mai bracket hu: " <<this->a << endl;
    }

};

int main(){

    B obj1, obj2;

    obj1.a=4;
    
    obj2.a=7;

    //calling overloaded operator
    obj1 + obj2;

    obj1();




    return 0;
}