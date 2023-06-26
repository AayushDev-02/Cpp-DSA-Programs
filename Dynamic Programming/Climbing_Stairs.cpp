class Solution {
public:
    
    //top Down approach
    int topDownSolve(int n, vector<int> &dp){
        if(n==0 || n==1){
            return 1;
        }

        if(dp[n] != -1) return dp[n];

        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp[n];
    }

    //bottom up approach
    int bottomUpSolve(int n, vector<int> &dp){

        //base case observe
        dp[0] = 1;
        dp[1] = 1;

        if(n==0) return 1;
        if(n==1) return 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }

    //space optimization approach
    int spaceOptSolve(int n){
        int p2 = 1;
        int p1 = 1;
        int curr;

        if(n==1) return 1;
        if(n==0) return 1;

        for(int i=2; i<=n; i++){
            curr = p2 + p1;
            p2 = p1;
            p1 = curr;
        }

        return curr;
    }
    
    int climbStairs(int n) {
        // if(n == 0 || n==1){
        //     return 1;
        // }

        // int ans = climbStairs(n-1) + climbStairs(n-2);
        // return ans;

        //create a dp array
        // vector<int> dp(n+1, -1);

        // int ans = topDownSolve(n, dp);
        // return ans;

        // int ans = bottomUpSolve(n, dp);
        // return ans;

        int ans = spaceOptSolve(n);
        return ans;


    }

    
};