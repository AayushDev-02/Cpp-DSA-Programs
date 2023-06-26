class Solution {
public:

    int solveRecursion(vector<int> &coins, int amount){
        //base case
        if(amount == 0){
            return 0;
        }

        if(amount < 0){
            return INT_MAX;
        }

        int mini = INT_MAX;

        for(int i=0; i<coins.size(); i++){
            int ans = solveRecursion(coins, amount - coins[i]);
            
            if(ans != INT_MAX){
               mini = min(mini, ans + 1);
            }
        }

        return mini;

    }

    int solveTopDown(vector<int> &coins, int amount, vector<int> &dp){

        if(amount == 0){
            return 0;
        }

        if(amount < 0){
            return INT_MAX;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini = INT_MAX;

        for(int i=0; i<coins.size(); i++){

            int ans = solveTopDown(coins, amount-coins[i], dp);

            if(ans != INT_MAX){
                mini = min(mini, ans + 1);
            }

        }

        dp[amount] = mini;
        return dp[amount];
    }

    //bottomup approach - tabulation
    int bottomUpSolve(vector<int> &coins, int amount){

        //create a dp array
        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;
        if(amount < 0){
            dp[amount] = INT_MAX;
        }

        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){

                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    int ans = dp[i - coins[j]];
                    dp[i] = min(dp[i], ans + 1);
                }



            }
        }

        return dp[amount];

    }

    int coinChange(vector<int>& coins, int amount) {
        

        // int ans = solveRecursion(coins, amount);

        // if(ans == INT_MAX) return -1;
        // return ans;


        // vector<int> dp(amount+1, -1);

        // int ans = solveTopDown(coins, amount, dp);
        // if(ans == INT_MAX) return -1;
        // return ans;

        int ans = bottomUpSolve(coins,amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};