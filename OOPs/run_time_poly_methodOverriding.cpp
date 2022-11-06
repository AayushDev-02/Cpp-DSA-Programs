#include <iostream>
using namespace std;


class animal{
    public:

    void speak(){
        cout << "SPEAKING" << endl ;
    }
};

class dog: public animal{

    public:
    //method overriding
    void speak(){
        cout << "BARKING" << endl;
    }
};

int main(){

    animal a;
    a.speak();

    dog b;
    b.speak();

    return 0;
}