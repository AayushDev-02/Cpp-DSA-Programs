#include <iostream>
#include <map>
#include <unordered_map>
// #include <bits/stdc++.h>
using namespace std;


int main(){

    // CREATION -------
    unordered_map<string , int> m;
    // unordered_map<int,int> m;

    // INSERTION

    // Method 1
    pair<string, int> pair1 = make_pair("Aayush", 3);
    m.insert(pair1);

    // Method 2
    pair<string , int> pair2("Yadav", 1);
    m.insert(pair2);

    // Method 3
    m["hai"] = 2;
    m["hai"] = 4;        // this updates the value of key - "mera" in the map ( from 2 to 4 )


    // SEARCHING ---------
    cout << m["hai"] << endl;
    cout << m.at("Aayush") << endl;

    // searching for a non existing key
    cout << m["Unknown key"] << endl;
    cout << m.at("Unknown key") << endl;


    // SIZE ----
    cout <<"Size of map is: "<< m.size() << endl;

    // CHECK PRESENCE
    cout << m.count("hai") << endl;
    cout << m.count("x") << endl;

    // ERASE
    m.erase("Unknown key");
    cout <<"Size of map is: "<< m.size() << endl;

    // ACCESSING

    // Method 1 - using for loop
    for(auto i:m){
        cout << i.first << " -> " << i.second << " , ";
    }
    cout << endl;
    
    // Method 2 - using iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while( it != m.end() ){         // traverse  until we reach end of the map
        cout << it->first << " -> " << it->second << " , ";
        it++;                       // increment iterator
    }
    cout << endl;


    return 0;
}