class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int prefixSum = 0;
        int count = 0;

        unordered_map<int,int> m;
        m[0] = 1;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];

            int element = prefixSum - k;

            count += m[element];

            m[prefixSum] += 1;
        }

        return count;

    }
};