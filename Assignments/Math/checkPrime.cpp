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

    int n = 0;

    bool ans = checkPrime(n);

    if(ans) cout << "Prime Number" << endl;
    else cout << "Not Prime Number" << endl;

    return 0;
}