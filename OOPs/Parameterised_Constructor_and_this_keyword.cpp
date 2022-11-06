#include <iostream>
using namespace std;    

class aayush{
    private:
    int health;

    public:

    aayush(){
        cout <<"Consturctor called" << endl;
    }

    //parameterised constructor :
    aayush(int health){
        cout << "this -> " << this << endl;
        this -> health = health;
    } 

    //Getter
    int getHealth(){
        return health;
    }

};

int main(){
    
    aayush a;
    cout << "Address of a object :" << &a << endl;

    aayush b(10);
    cout << "Address of b object :" << &b << endl;

    a.getHealth();
    
}