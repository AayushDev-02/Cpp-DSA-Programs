#include <iostream>

#include <set>
using namespace std;


class person{
    public:
    float age;
    string name;

    //for comparision - operator overloading - ascending
    bool operator < (const person& rhs) const {return age<rhs.age;}
    //for comparision - operator overloading - descending
    bool operator > (const person& rhs) const {return age>rhs.age;}
};


int main(){
    //duplicates not allowed and sorted - ascending order
    set<int> s = {1,4,3,5,2,0,1,2};

    for(auto i: s){
        cout << i << endl;
    }

    cout << endl;

    //user defined set - will not work because we cannot compare string
    set<person> a = {{30, "Rupesh"}, {25,"Aayush"}, {34, "Kajal"}};

    for(auto i: a){
        cout << i.age << " " << i.name << endl;
    }

    cout << endl;

    //descending order
    set<person, greater<>> b = {{30, "Rupesh"}, {25,"Aayush"}, {34, "Kajal"}};

    for(auto i: b){
        cout << i.age << " " << i.name << endl;
    }

    cout << endl;

    set<int> x;

    x.insert(5);
    x.insert(4);
    x.insert(0);
    x.insert(0);
    x.insert(5);
    x.insert(2);
    x.insert(5);
    x.insert(2);
    x.insert(4);
    x.insert(0);

    for(auto i:x){
        cout << i << endl;
    }

    cout << endl;

    set<int>::iterator it = x.begin();
    it++;

    // x.erase(x.begin());
    x.erase(it);

    for(auto i:x){
        cout << i << endl;
    }

    cout << endl;

    cout << " -5 is present or not: " << s.count(-5) << endl; 

    // set<int>::iterator itr = s.find(5);

    // cout << *it << endl;


    return 0;

}
