#include <iostream>
#include <string.h>
using namespace std;
 
class hero{

    public:
    char *name; // good practise
    // char name[100];      // not a good practise - we use heap as we have more space available in heap

    int health;
    char level;

    hero(int health){
        this->health = health;
    }

    hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    hero(){
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    //copy constructor
    hero(hero &temp){


        // DEEP COPY
        char *ch = new [strlem(temp.name) + 1];
        strcpy (ch,temp.name);
        this.name = ch;

        cout << "copy constructor called";

        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "Name: " << this->name << ", ";
        cout << "Health is : " << this->health <<", ";
        cout << "Level is : " << this->level <<", ";
        cout <<endl<< endl;
    }

    void setName(char name[]){
        strcpy(this->name, name);       //shallow copy
    }

    

};



int main(){

    // hero s(70,'c');
    // s.print();

    // hero r(s);
    // r.print();


    hero h1;
    h1.health =12;
    h1.level ='D';

    char name[7] = "aayush";
    h1.setName(name);

    h1.print();

    cout << endl;
    //use default copy constructor
    hero h2(h1);
    h2.print();


    h1.name[0] = 'G';
    h1.print();            // name in h1 changed
    h2.print();         // shallow copy example - h2 also change and G is added - this is called shallow copy
    return 0;
}