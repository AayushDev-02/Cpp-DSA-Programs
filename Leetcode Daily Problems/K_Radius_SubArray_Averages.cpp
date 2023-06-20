class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n, -1);
        if(2*k+1 > n) return ans;
        
        unsigned long long sum = 0;
        int avg = 0;

        int leftStart = k;
        int rightStart = nums.size() - k ;
        

        //first avg
        for(int i=0; i<2*k+1; i++){
            sum+= nums[i];
        }

        avg = sum/(2*k + 1);
        ans[leftStart] = avg;

        for(int i=leftStart+1; i<rightStart; i++){

            sum+= nums[k+i] - nums[i-k-1];
            ans[i] = sum/(2*k+1);
        }

        return ans;

       
    }
};