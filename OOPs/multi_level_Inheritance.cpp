#include <iostream>
using namespace std;

//Example of multo level inheritance

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

class germanShephard : public dog{

};

int main(){

    germanShephard g;
    g.speak();

    return 0;
}