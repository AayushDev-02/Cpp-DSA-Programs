#include <iostream>
using namespace std;

int main(){

    int amount;
    cout<<"Enter amount value: "<<endl;
    cin>>amount;

    int hun,twenty,one;

    hun=amount/100;
    amount=amount-hun*100;

    twenty=amount/20;
    amount=amount-twenty*20;

    one=amount/1;

    cout<<"No of hundred rs notes: "<<hun<<endl;
    cout<<"No of twenty rs notes: "<<twenty<<endl;
    cout<<"No of one rs notes: "<<one<<endl;

    return 0;
}