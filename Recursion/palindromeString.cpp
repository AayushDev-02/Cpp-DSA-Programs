#include <iostream>
using namespace std;

bool checkPalindrome(string s, int i, int j){

    //base case
    if(i>j){
        return true;
    }

    // processing
    if(s[i] != s[j]){
        return false;
    }else{
        //recursive relation
        return checkPalindrome(s,++i,--j);
    }

}

bool checkPalindrome_singlePointer(string s, int i){

    //base case
    if( i > (s.length() - (1+i)) ){
        return true;
    }

    // processing
    if(s[i] != s[s.length() - (1+i)]){
        return false;
    }else{
        //recursive relation
        return checkPalindrome_singlePointer(s,++i);
    }

}

int main(){

    string s;
    cout << "Enter string : ";
    cin >> s;

    bool ans = checkPalindrome(s,0,s.length()-1);

    if(ans){
        cout << "String is plaindrome " << endl;
    }else{
        cout << "String is not plaindrome " << endl;
    }

    cout << endl;

    bool ans2 = checkPalindrome_singlePointer(s,0);

    if(ans){
        cout << "String is plaindrome " << endl;
    }else{
        cout << "String is not plaindrome " << endl;
    }

    return 0;
}