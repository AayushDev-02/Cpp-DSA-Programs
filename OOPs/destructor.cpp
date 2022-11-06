#include <iostream>
using namespace std;

class hero{
    public:
    //defining our own destructor
    ~hero(){
        cout << "Destructor called" << endl;
    }

};


int main(){

    //startic aalocation
    hero h1;

    //Dynamic allocation
    hero *h2 = new hero;
    //manually destructor call  
    delete b; 



    return 0;
}