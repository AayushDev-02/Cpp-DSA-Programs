//similar to permutationOfString

class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index){
        
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j = index; j<nums.size(); j++){
            swap(nums[index], nums[j]);            // - this will swap each index to first or index value
            solve(nums, ans, index+1);

        //backtracking
            swap(nums[index], nums[j]);              // - returning to original string to solve for next index
        

    }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        
        solve(nums, ans, index );

        return ans;
    }
};