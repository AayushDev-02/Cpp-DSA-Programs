#include <iostream>
using namespace std;

int solveUsingRecursion(int n, int k){

    //base case
    if(n == 1){ // only 1 fence - thus we can paint in k colors 
        return k;
    }

    if(n == 2){
        return ( k + k * (k-1) ); 
    }


    int ans = (solveUsingRecursion(n-2,k) + solveUsingRecursion(n-1,k)) * (k-1);

    return ans;
}


int main(){

    int n =4;
    int k = 3;

    int ans = solveUsingRecursion(n, k);

    cout << ans << endl;

    return 0;
}