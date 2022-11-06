#include <iostream>
using namespace std;

//creating parent class
class human{
    public: 
    int height;
    int weight;
    int age;

    private:
    int age1;

    int getAge(){
        return this->age;
    }
     public:
    void setWeight(int weight){
        this->weight = weight;
    }

};

//creating child class
class male : public human{

    public:
    string color;

    void sleep(){
        cout << "Male sleeping" << endl;
    }


};
// in protected members of parent class are allowed in the child class
class female : protected human{

    public:
    int getHeight(){
        return this->height;
    }

};


int main(){

    male obj1;

    cout << obj1.age << endl;
    cout << obj1.height << endl;
    cout << obj1.weight << endl;
    cout << obj1.color << endl;

    obj1.sleep();

    obj1.setWeight(85);
    cout << obj1.weight << endl;

    //Error as age1 is a private member
    // cout << obj1.age1 << endl;

    female obj2;

    //since the height member of female obj is not accessible outside the class female and human, we are using a public method to access protected member of femal - height
    cout << obj2.getHeight() << endl;





    return 0;
}    