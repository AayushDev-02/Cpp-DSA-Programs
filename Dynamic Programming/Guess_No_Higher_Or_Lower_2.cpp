class Solution {
public:

    int solveUsingRecursion(int start, int end){
        if(start >= end) return 0;

        int ans = INT_MAX;

        for(int i = start ; i <= end; i++){

            int lower = solveUsingRecursion(start, i-1);
            int higher = solveUsingRecursion(i+1, end);

            ans = min(ans, i + max(lower, higher));

        }

        return ans;
    }

    int usingMemoisation(int start, int end, vector<vector<int>> &dp){

        if(start >= end) return 0;

        if(dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;

        for(int i = start ; i <= end; i++){

            int lower = usingMemoisation(start, i-1, dp);
            int higher = usingMemoisation(i+1, end, dp);

            ans = min(ans, i + max(lower, higher));

        }

        dp[start][end] = ans;

        return ans;

    }

    int usingTabulation( int n) {

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int start = n; start >=1; start--){
            for(int end = 1; end <= n; end++){
                
                if(start >= end){
                    continue;
                }
                else{

                    int ans = INT_MAX;

                    for(int i = start ; i <= end; i++){

                        int lower = dp[start][i-1];
                        int higher = dp[i+1][end];

                        ans = min(ans, i + max(lower, higher));

                    }

                    dp[start][end] = ans;

                }
            }
        }

        return dp[1][n];

    }

    int getMoneyAmount(int n) {

        // int ans = solveUsingRecursion(1, n);

        //Memoisation
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = usingMemoisation(1, n, dp); 

        int ans = usingTabulation(n);


        return ans;
    }
};