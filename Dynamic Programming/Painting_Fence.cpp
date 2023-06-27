#include <iostream>
#include <vector>
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

int topDownApproach(int n, int k, vector<int> &dp){
    //base case
    if(n == 1){ // only 1 fence - thus we can paint in k colors 
        return k;
    }

    if(n == 2){
        return ( k + k * (k-1) ); 
    }

    if(dp[n] != -1) return dp[n];


    dp[n] = (topDownApproach(n-2,k, dp) + topDownApproach(n-1,k, dp)) * (k-1);

    return dp[n];   
}

//Tabular method
int bottomUpApproach(int n, int k){

    vector<int> dp(n+1, 0);

    dp[1] = k;
    dp[2] = ( k + k * (k-1) );

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-1]) * (k-1);
    }

    return dp[n];
}

//space soptimisation
int spaceOpt(int n, int k){

    int p1 = k;
    int p2 = ( k + k * (k-1) );
    int curr;
    for(int i=3; i<=n; i++){
        curr = (p2 + p1) * (k-1);
        p1 = p2;
        p2 = curr;
    }

    return p2;

}

int main(){

    int n = 4;
    int k = 3;

    // int ans = solveUsingRecursion(n, k);

    // vector<int> dp(n+1, -1);
    // int ans = topDownApproach(n, k, dp);

    // int ans = bottomUpApproach(n,k);

    int ans  = spaceOpt(n,k);

    cout << ans << endl;

    return 0;
}