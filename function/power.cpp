#include <iostream>
using namespace std;

int power(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }

    return ans;
}


int main(){
    int a=2;
    int b=3;

    int ans=power(2,3);

    cout<<"Answer is : "<<ans;


    return 0;
}