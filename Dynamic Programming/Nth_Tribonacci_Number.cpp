class Solution {
public:

    int solveRecursion(int n){
        if(n == 0){
            return 0;
        }

        if(n == 1 || n == 2){
            return 1;
        }

        int ans = solveRecursion(n-3) + solveRecursion(n-2) + solveRecursion(n-1);

        return ans;
    }

    int tribonacci(int n) {
        //Using recursion
        int ans = solveRecursion(n);
        return ans;
    }

    // ---------------------------------

    //Top Down Appraoch
    int topDownApproach(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }

        if(n == 1 || n == 2){
            return 1;
        }

        //check if n is already calculated
        if(dp[n] != -1) return dp[n];

        dp[n] = topDownApproach(n-3, dp) + topDownApproach(n-2, dp) + topDownApproach(n-1, dp);

        return dp[n];
    }

    int tribonacci(int n) {

        //create a dp array
        vector<int> dp(n+1, -1);

        int ans = topDownApproach(n, dp);
        return ans;
    }

    ---------------------------------

    Bottom Up Appraoch - Tabular Method (Iterative)
    int bottomUpApproach(int n){
        //creating a dp array
        vector<int> dp(n+1, 0);

        if(n == 0) return 0;
        if(n==1 || n==2) return 1;

        //checking base case
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        //traversing the array from 3 -> n with n included
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }

    int tribonacci(int n) {
        int ans = bottomUpApproach(n);
        return ans;
    }

    // ---------------------------------

    //Space Optimization Approach - Using variables
    int spaceOpt(int n){

        if(n==0) return 0;
        if(n == 1 || n == 2) return 1;

        int p3 = 0;
        int p2 = 1;
        int p1 = 1;

        int curr;

        for(int i=3; i<=n; i++){
            curr = p3 + p2 + p1;

            p3 = p2;
            p2 = p1;
            p1 = curr;
        }

        return p1;


    }

    int tribonacci(int n) {
        int ans = spaceOpt(n);
        return ans;
    }
};