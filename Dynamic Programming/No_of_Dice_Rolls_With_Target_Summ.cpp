class Solution {
public:
    int mod = 1e9 + 7;
    int solRec(int n, int k, int target){

        if(n < 0){
            return 0;
        }

        if(n == 0 && target == 0){
            return 1;
        }

        if(n == 0 && target != 0){
            return 0;
        }

        if(n != 0 && target == 0){
            return 0;
        }

        int ans = 0;

        for(int i=1; i<=k; i++){
            ans += solRec(n-1, k, target - i);
        }

        return ans;

    }

    int topDown(int n, int k, int target, vector<vector<int>> &dp){
        if(n < 0){
            return 0;
        }

        if(n == 0 && target == 0){
            return 1;
        }

        if(n == 0 && target != 0){
            return 0;
        }

        if(n != 0 && target == 0){
            return 0;
        }

        if(dp[n][target] != -1) return dp[n][target];

        int ans = 0;

        for(int i=1; i<=k; i++){
            if(target - i >= 0){
                ans = (ans % mod + (topDown(n-1, k, target - i, dp))%mod) % mod;
            }
        }

        dp[n][target] = ans;
        return dp[n][target];
    }

    int bottomUp(int n, int k, int target){

        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

        dp[0][0] = 1;


        for(int index = 1; index <=n; index++){
            for(int t = 1; t <= target; t++){

                int ans = 0;

                for(int i=1; i<=k; i++){
                    if(t - i >= 0){
                        ans = (ans % mod + (dp[index-1][ t - i])%mod) %mod;
                    }

                    dp[index][t] = ans;
                }
            }
        }

        return dp[n][target];
         
    }

    int spaceOpt(int n, int k, int target){
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index = 1; index <=n; index++){
            for(int t = 1; t <= target; t++){

                int ans = 0;
 
                for(int i=1; i<=k; i++){
                    if(t - i >= 0){
                        ans = (ans % mod + (prev[ t - i])%mod) %mod;
                    }

                    curr[t] = ans;
                }
            }

            //shifting
            prev = curr;
        }

        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {

        // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        // int ans = topDown(n, k, target, dp);

        // int ans = bottomUp(n, k, target);
        int ans = spaceOpt(n, k, target);

        return ans;
    }
};