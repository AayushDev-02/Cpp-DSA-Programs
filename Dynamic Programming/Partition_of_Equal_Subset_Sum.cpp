class Solution {
public:

    bool solRec(vector<int>&nums, int index, int target){
        //base cases
        if(index >= nums.size()){
            return false;
        }

        if(target < 0){
            return false;
        }

        if(target == 0){
            return true;
        }

        bool include = solRec(nums, index+1, target - nums[index]);
        bool exclude = solRec(nums, index+1, target);

        return (include || exclude);


    }

    bool topDown(vector<int>&nums, int index, int target, vector<vector<int>> &dp){
        //base cases
        if(index >= nums.size()){
            return false;
        }

        if(target < 0){
            return false;
        }

        if(target == 0){
            return true;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool include = topDown(nums, index+1, target - nums[index], dp);
        bool exclude = topDown(nums, index+1, target,dp);

        bool ans = (include || exclude);

        dp[index][target] = ans;

        return dp[index][target];

    }

    //Bottom Up Approach
    bool bottomUp(vector<int> &nums, int target){

        vector<vector<int>> dp(nums.size()+1, vector<int> (target+1, 0));
        int n = nums.size()-1;

        //for every target = 0 -> return true;
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        for(int i = n-1; i>=0; i--){
            for(int t = 1; t<=target; t++){
                bool include = 0;
                if(t - nums[i] >= 0){
                    include = dp[i+1][t - nums[i]];
                }
                bool exclude = dp[i+1][t];

                bool ans = (include || exclude);

                dp[i][t] = ans;

            }
        }

        return dp[0][target];

    }



    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum+=i;
        }
        if(sum%2 != 0) return false;    //yaha hi galti karunga

        int target = sum/2;
        int index = 0;

        // bool ans = solRec(nums, index, target);

        //TOP DOWN
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (target+1, -1));
        // bool ans = topDown(nums, index, target, dp);

        bool ans = bottomUp(nums, target );


        return ans; 
    }
};