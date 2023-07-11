class Solution {
public:

    bool check(vector<int> & a, vector<int> &b){
        if(b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2]){
            return true;
        }

        return false;
    }

    int spaceOpt(vector<vector<int>> &nums) {
        int n = nums.size();
        vector<int> currRow(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int curr = nums.size()-1; curr >= 0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || check(nums[curr], nums[prev])) {
                    include = next[curr + 1] + nums[curr][2];
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

    int maxHeight(vector<vector<int>>& cuboids) {
        
        //sort every array
        for(auto &i: cuboids ){
            sort(i.begin(), i.end()); 
        }

        //sort the 2d array - according the width
        sort(cuboids.begin(), cuboids.end());

        //apply LIS logic
        int ans = spaceOpt(cuboids);
        return ans;

    }
};