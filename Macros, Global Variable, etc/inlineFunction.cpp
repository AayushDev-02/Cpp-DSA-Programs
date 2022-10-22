#include <iostream>
using namespace std;

void func(int a,int b){
    a++;
    b++;
    cout << a << b << endl;
}

inline int getMax(int& a, int& b){          //inline function
    return (a>b) ? a : b;
}

int main(){

    int a =1; 
    int b = 2; 
    int ans = 0;

    // if(a>b){
    //     ans = a;
    // }else{
    //     ans = b;
    // }

    //tertiary operator

    ans = (a>b) ? a : b;

    cout << ans << endl;

    a+=3;
    b+=1;

    cout << getMax(a,b) << endl;



    return 0;
}