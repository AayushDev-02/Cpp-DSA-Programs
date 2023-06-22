#include <iostream>
using namespace std;

int factorial(int n){
    int ans=1;
    for(int i=n; i>0; i--){
        ans*=i;
    }

    return ans;
}

int main(){

    int n = 5;
    int ans = factorial(n);
    
    cout << ans;
    return 0;
}