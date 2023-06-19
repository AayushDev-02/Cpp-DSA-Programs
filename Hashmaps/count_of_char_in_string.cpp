#include <iostream>
#include<string>
#include<unordered_map>

using namespace std;



int main(){

    string s = "thiruvananthapuram";
    unordered_map<char, int> m;

    for(int i=0; i<s.length(); i++){
        m[s[i]]++;
    }

    for(auto i: m){
        cout << i.first << "->" << i.second << endl;
    }

    return 0;
}