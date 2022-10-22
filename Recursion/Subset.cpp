#include <iostream>
#include <vector>
using namespace std;




class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int i, vector<vector<int>>& ans){
        
        //base case
        if(i >= nums.size()){
            ans.push_back(output);      // pushing output vector array in ans when i = size of nums
            return;
        }


        //exclude case - we dont have to add anything just increase index
        solve(nums, ans , ++i, ans);            // Recursive relation


        //include case - add index element in output and increase index 
        output.push_back(nums[i]);
        solve(nums, ans , ++i, ans);            // Recursive Relation
        

    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;

        vector<int> output;
        solve(nums, output , 0 , ans);

       

        return ans;
        
    }
};


int main(){



    return 0;
}