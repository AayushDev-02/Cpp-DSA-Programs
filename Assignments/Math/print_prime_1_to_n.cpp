#include <iostream>
#include <math.h>
using namespace std;


bool checkPrime(int n){

    if(n==1 || n==0) return false;

    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }

    return true;
}

int main(){

    int n =77;

    for(int i=1; i<=n; i++){
        bool ans = checkPrime(i);
        if(ans) cout << i << " ";
    }

    cout << endl;


    

    return 0;
}