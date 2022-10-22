#include <iostream>
// #include "Hero.cpp"         // hero class is added  // method 1
using namespace std;

//method 2
class hero{

    public:
    int health;
    char level;

    private: //access inside the class
    // char level;

    void print(){
        cout << level << endl;      // level is accessible or working here because it is presesnt inside class
    }

};



int main(){

    //object creation
    hero h1;

    // cout << "Size : " << sizeof(h1) <<endl;

    h1.health=70;
    h1.level='A';




    //accessing
    cout << "Health is " << h1.health << endl;      // public - can be accessed anywhere
    cout << "Level is " << h1.level << endl;        // Error as it is present outside class - private

    return 0;
}