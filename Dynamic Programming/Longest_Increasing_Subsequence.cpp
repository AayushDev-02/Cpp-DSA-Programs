class Solution {
public:

    int solRec(vector<int> &nums, int curr, int prev){

        if(curr >= nums.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            include = solRec(nums, curr + 1, curr) + 1;
        }
        
        int exclude = solRec(nums, curr+1, prev );

        return max(include, exclude);
    }

    int solMemoization(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp){

        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev + 1] != -1) return dp[curr][prev+1]; 

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            include = solMemoization(nums, curr + 1, curr, dp) + 1;
        }
        
        int exclude = solMemoization(nums, curr+1, prev, dp );

        //to make prev a valid index
        dp[curr][prev+1] = max(include, exclude);

        return dp[curr][prev+1];
    }

    int solTabulation(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int curr = nums.size()-1; curr >= 0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]) {
                    include = dp[curr + 1][curr + 1] + 1;
                }
                
                int exclude = dp[curr+1][prev + 1];

                //to make prev a valid index
                dp[curr][prev+1] = max(include, exclude);
            }
        }

        return dp[0][0];

    }

    int spaceOpt(vector<int> &nums) {
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int curr = nums.size()-1; curr >= 0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]) {
                    include = next[curr + 1] + 1;
                }
                
                int exclude = next[prev + 1];

                //to make prev a valid index
                currRow[prev+1] = max(include, exclude);
            }

            //shifting
            next = currRow;
        }

        return next[0];

    }

    int lengthOfLIS(vector<int>& nums) {

        int curr = 0;
        int prev = -1;

        // int ans = solRec(nums, curr, prev );

        // vector<vector<int>> dp(nums.size(), vector<int> (nums.size()+1, -1));
        // int ans = solMemoization(nums, curr, prev, dp);
        // int ans = solTabulation(nums);
        
        int ans = spaceOpt(nums);
        return ans;


    }
};