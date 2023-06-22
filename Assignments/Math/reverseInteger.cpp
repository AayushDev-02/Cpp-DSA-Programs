#include <iostream>
using namespace std;

int solve(int n){
    int ans = 0;
    while(n > 0){
        int unit = n%10;
        ans = ans*10 + unit;
        n = n/10;
    }

    return ans;
}


int main(){

    int n = -8212431;
    
    int x = abs(n);
    int ans = solve(x);
    if(n>= 0){

        cout << "Reverse:  "  << ans << endl;
    }else{

        cout << "Reverse:  "  << -1*ans << endl;
    }

    return 0;
}