#include <iostream>
#include <map>
using namespace std;


int main(){

    map<int, string> m;

    m[1] = "Aayush";
    m[2] = "Mummy";
    m[13] = "Papa";

    m.insert({5, "Kratos"});

    cout << endl;
    //printing
    cout << "Before erase : " << endl ;
    for(auto i:m){
        cout << i.first << " "<< i.second <<  endl;
    }
    cout << endl;

    cout << "finding -13 : " << m.count(-13) << endl;
    cout << endl;

    m.erase(13);
    cout << "After erase : " << endl ;
    for(auto i:m){
        cout << i.first << " "<< i.second <<  endl;
    }

    cout << endl;

    auto it =  m.find(5);

    for(auto i = it; i!=m.end(); i++){
        cout << (*i).first << endl;
    }

    return 0;
}