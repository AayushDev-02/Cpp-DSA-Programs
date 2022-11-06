#include <iostream>
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

    //dynamic allocation
    hero *b = new hero;

    //accessing values
    cout << "Level is: " << (*b).level << endl;
    cout << "Health is: " << (*b).getHealth() << endl;
    cout << endl;

    b->setHealth(70);
    b->setLevel('A');

    //accessing values - 2nd method
    cout << "Level is: " << b->level << endl;
    cout << "Health is: " << b -> getHealth() << endl;

    return 0;

}