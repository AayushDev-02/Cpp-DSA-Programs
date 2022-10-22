#include <iostream>
using namespace std;

int gcd(int a,int b){

    if(a==0){
            return b;    
    }

    if(b==0){
            return a;
    }

    while(a!=b){
        if(a>b){
            a=a-b;
        }else{
            b=b-a;
        }
    }
    return a;    
}

int main(){

    int a,b;
    cin>>a>>b;

    cout<<"GCD of a and b is : "<<gcd(a,b) << endl;



    return 0;
}