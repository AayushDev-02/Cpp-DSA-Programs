#include <iostream>
using namespace std;

class hero{
    public:
    
    static int timetoComplete;      //creating an static data member 

};

//initializing - outside the class
int hero::timetoComplete = 5;

int main(){

   //accessing the member - no class object required
   cout << hero :: timetoComplete << endl;

   //accessing using object - this approach is not recommended 
   hero h1;

   cout << h1.timetoComplete << endl; 



    return 0;
}