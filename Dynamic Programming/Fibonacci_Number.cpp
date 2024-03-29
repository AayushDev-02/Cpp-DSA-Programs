//THIS IS TOP DOWN DP APPROACH

class Solution {
public:
    //Recursion + Memoisation   
    int topDownSolve(int n, vector<int> &dp){
        if(n==0 || n==1){
            return n;
        } 

        //memoisation step 2: write the condition to check if ans already exists
        if(dp[n] != -1){
            return dp[n];
        }

        //replace ans with dp[n]
        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);

        return dp[n];
    }

    //THIS IS BOTTOM UP DP APPROACH
    int bottomUpSolve(int n){
        //step 1: create dp array
        vector<int> dp(n+1, -1);

        //step 2: observe base case in the above solution
        dp[0] = 0;
        dp[1] = 1;

        //step 3: check execution of top down
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    //SPACE OPTIMIZATION METHOD
    int spaceOptSolve(int n){
        
        //we dont need dp array
        int prev2 = 0;
        int prev1 = 1;
        int curr;

        if(n==0) return 0;

        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            //shifting
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }



    int fib(int n) {
        
        //Memoisation
        //Step 1: creating a dp array
        vector<int> dp(n+1, -1);

        //Dp using recursion
        int ans = topDownSolve(n, dp);

        return ans;
    }
};