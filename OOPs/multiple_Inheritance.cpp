#include <iostream>
using namespace std;


class Animal{
    public:
    int weight;
    int age;

    void bark(){
        cout << "BARKING" << endl ;
    }
};

class human {
    public:
    string color;

    void speak(){
        cout << "SPEAKING" << endl ;
    }


};

//Using multiple inheritance -

class hybrid: public Animal, public human{

};


int main(){

    hybrid obj1;

    obj1.speak();
    obj1.bark();

    return 0;
}