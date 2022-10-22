#include <iostream>
using namespace std;

void reverseString(string &s, int i, int j){

    //base case
    if(i>j){
        return ;
    }
    
    swap(s[i],s[j]);
    i++;
    j--;
    return reverseString(s, i,j);

    //or
    // return reverseString(s,size, ++i, --j);


    
}

//using single pointer
void reverseString_singlePointer(string &s, int i){
    if(i > s.length()-1-i){
        return;
    }

    swap(s[i],s[s.length()-(1+i)]);
    i++;
    return reverseString_singlePointer(s,i);
}



int main(){

    string s ;
    cout << "Enter string : " ;
    cin >> s;
    int size = s.length();

    int i =0;
    int j =size-1;

    reverseString(s,i,j);
    cout << "Answer using 2 pointer : " << s << endl;

    cout << endl;

    string s2 = "abcde";
    reverseString_singlePointer(s2,i);
    cout << "Answer using 1 pointer : " << s2 << endl;

    return 0;
}