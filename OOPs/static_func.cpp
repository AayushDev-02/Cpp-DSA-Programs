#include <iostream>
using namespace std;

class hero{
    public:
    int health;
    char level;
    
    static int timetoComplete;      //creating an static data member 

    //creating static function
    static int random(){
        // cout << this->health << endl; ---------------------// this will give error because this is not there in static functions (cout/return)

        // cout << health << endl;     ----------------------- this will give error because health is not a static member   (cout/return)

             
        return timetoComplete;                          // this works because timetoComplete is a static member
    }

};

//initializing - outside the class
int hero::timetoComplete = 5;

int main(){

   //accessing the member - no class object required
   cout << hero :: timetoComplete << endl;

   //accessing static function
   cout << hero :: random() << endl;

   



    return 0;
}