#include <iostream>
// #include "Hero.cpp"         // hero class is added  // method 1
using namespace std;

class hero{
    private :
    int health =00;

    public:
    char level = 'D';

    void print(){
        cout << level << endl;
    }

    //Getter
    int getHealth(){
        return health;
    }

    int getLevel(){        //Getter
        return level;
    }

    //Setters:
    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){  // setter
        level = ch;
    }

};



int main(){
   // static allocation
   hero aayush; 

   //dynamic allocation
   hero *b = new hero;
    cout << "Level is: " << (*b).level << endl;
    cout << "Health is: " << (*b).getHealth() << endl;




   cout << "Size of aayush output : " << sizeof(aayush) << endl; 

   cout << "Health of aayush is : " << aayush.getHealth() << endl; // getting value using getter

   aayush.setHealth(70);  // setting value using setter
   cout << "Health of aayush is : " << aayush.getHealth() << endl; // getting value using getter


    return 0;
}