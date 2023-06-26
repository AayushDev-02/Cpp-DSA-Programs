class Solution {
public:
    // n -> represents the index of current house 
    int solveRec(vector<int>& nums, int n){
        if(n < 0 ){
            return 0;
        }

        if(n==0){
            return nums[0];
        }

        //include case
        int include = solveRec(nums, n-2) + nums[n];


        //exclude case
        int exclude = solveRec(nums,n-1);

        return max(include , exclude);


    }

    //top down approach
    int topDownSolve(vector<int> &nums, int n, vector<int> &dp){
        //base case
        if(n < 0){
            return 0;
        }

        if(n==0){
            return nums[0];
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int include = topDownSolve(nums, n-2, dp) + nums[n];
        int exclude = topDownSolve(nums, n-1, dp);

        dp[n] = max(include, exclude);
        return dp[n];

    }

    //bottom up approach
    int bottomUpSolve(vector<int> &nums, int n){

        //create a dp array
        vector<int> dp(n+1,0);

        dp[0] = nums[0];

        for(int i=1; i<=n; i++){
            //include case
            int include;
            if(i-2 >= 0){
                 include = dp[i-2] + nums[i];
            }
            else{
                 include = nums[i];
            }

            int exclude = dp[i-1];
            dp[i] = max(include , exclude);


        }

        return dp[n];

    }

    int spaceOptSolve(vector<int> &nums, int n){

        int prev2 = 0;
        int prev1 = nums[0];
        int curr=0;

        for(int i=1; i<=n; i++){

            int include = prev2 + nums[i];
            int exclude = prev1;

            curr = max(include , exclude);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;

    }

    int rob(vector<int>& nums) {
        // return solveRec(nums, nums.size()-1);
        int n = nums.size()-1;
        // vector<int> dp(n+1, -1);
        // int ans = topDownSolve(nums, n, dp);
        // return ans;

        // return bottomUpSolve(nums, n);

        return spaceOptSolve(nums, n);
    }
};