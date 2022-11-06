#include <iostream>
using namespace std;

//Example of single inheritance

class Animal{
    public:
    int weight;
    int age;

    void speak(){
        cout << "SPEAKING" << endl ;
    }
};

class dog: public Animal{

};


int main(){

    dog d;
    d.speak();

    cout << d.age << endl;

    return 0;
}