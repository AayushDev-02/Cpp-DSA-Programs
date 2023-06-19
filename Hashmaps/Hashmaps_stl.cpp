#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){

    //creation
    unordered_map<string, int> m;

    //insertion
    m["Aayush"] = 2002;
    
    pair<string, int>p = make_pair("X", 2000);;
    m.insert(p);

    pair<string, int> p2("Y", 1995);
    m.insert(p2);

    m.insert({"Z", 1990});

    //accessing
    cout << m["Aayush"] << endl;
    
    cout << endl;

    cout << m.at("Aayush") << endl;
    cout << m.at("X") << endl;
    cout << m.at("Y") << endl;
    cout << m.at("Z") << endl;
    cout << endl;

    //Searching
    cout << "Searching : " << endl;

    //count function
    cout << m.count("X") << endl;
    
    //find function
    if(m.find("Aayush") != m.end()){
        auto iterator = m.find("Aayush");
        cout << "Key is found : " << iterator->second << endl;
    }
    else{
        cout << "Key is not found";
    }

    //Size 
    cout << "Size of the unordered_map is: " << m.size() << endl;

    //note using m["A"] to find it a key in unordered_map leads to - it creating an entry in the map with 0 as its value
    //therefore look at this example
    cout << m.size() << endl;   //size 4
    cout << m["A"] << endl;     // retunrs 0 as no key matches but also creates a key value with 0 as value
    cout << m.size() << endl;   //size 5
    
    //iteration
    cout << "Printing all elements: " << endl;
    for(auto i: m){
        cout << i.first << " -> " << i.second << endl;
    }


    return 0;
}