#include<iostream>
using namespace std;

int main(){

    char ch;
    cin.get(ch);
    int a=int(ch);
    cout<<a<<endl;
    if(97<=a && a<=122){
        cout<<"Lower case"<<endl;
    }else if(65<=a && a<=90){
        cout<<"Upper Case"<<endl;
    }else if(48<=a && a<=57){
        cout<<"Numeric Number"<<endl;

    }else{
        cout<<"Special Character";
    }

    return 0;
}