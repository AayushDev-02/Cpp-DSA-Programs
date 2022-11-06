#include <iostream>
using namespace std;

class aayush{
    public:

    //constructor :
    aayush(){
        cout << "Constructor is called" << endl;
    } 

};

int main(){
    
    cout << "hello" << endl;

    //creating an object:
    aayush a;

    cout << "Hello" << endl;


    //dynamically
    aayush *b= new aayush;
    //or
    aayush *c= new aayush();


}