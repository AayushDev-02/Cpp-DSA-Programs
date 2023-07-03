#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int paintingStairsRec(int n, int k){

    if(n==1){
        return k;
    }

    if(n == 2) {
        return k*k;
    }

    //recursive relation
    int ans = (paintingStairsRec(n-1, k) + paintingStairsRec(n-2, k))*(k-1);

    return ans;

}

//top down approach - painting fence
int paintingFenceTopDown(int n, int k, vector<int> &dp){

    if(n==1){
        return k;
    }

    if(n == 2) {
        return k*k;
    }

    if(dp[n] != -1) return dp[n];

    //recursive relation
    dp[n] = (paintingFenceTopDown(n-1, k, dp) + paintingFenceTopDown(n-2, k, dp))*(k-1);

    return dp[n];
}

//bottom up approach
int paintingFenceBottomUp(int n, int k){

    if(n==1) return k;
    if(n==2 ) return k*k;

    //create a dp
    vector<int> dp(n+1, 0);
    
    dp[1] = k;
    dp[2] = k*k;

    for(int i=3; i<=n; i++){

        dp[i] = (dp[i-1] + dp[i-2])* (k-1);

    }

    return dp[n];
}

//space optimization
int paintingFenceSpaceOpt(int n, int k){

    int prev1 = k;
    int prev2 = k*k;

    for(int i=3; i<=n; i++){
        int curr = (prev1 + prev2) * (k-1);

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;

}


int main(){

    int n = 4;
    int k = 3;

    //Painting Stairs
    // int ans = paintingStairsRec(n, k);

    // vector<int> dp(n+1, -1);
    // int ans = paintingFenceTopDown(n, k, dp);

    // int ans = paintingFenceBottomUp(n, k);

    int ans = paintingFenceSpaceOpt( n,  k);

    cout << ans << endl;


    return 0;
}