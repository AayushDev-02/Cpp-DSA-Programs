class Solution {
public:

    int help(map<pair<int,int>, int> &dp, int prev, int i, vector<int>&arr1, vector<int>& arr2){

        if(i == arr1.size()) return 0;  //reach end of array

        if(dp.find({i,prev})!=dp.end()) {   //memoization check
            return dp[{i, prev}];   
        }

        int ans = INT_MAX/2; // not INT_MAX because we are later adding by 1

        //next higher element;
        int id = upper_bound(arr2.begin(),arr2.end(), prev) - arr2.begin();

        //move on call
        if(arr1[i] > prev){
            ans = min(ans, help(dp,arr1[i], i+1, arr1, arr2));
        }

        //replace call
        if(id < arr2.size()){   
            ans = min(ans, help(dp, arr2[id], i+1, arr1, arr2) + 1);
        }

        return dp[{i,prev}] = ans; // memoization


    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());     //sort array to search greedly for next bigger element
        map<pair<int,int>, int> dp;
                    //(Memorization, prev, i, arr1, arr2)
        int ans = help(dp, INT_MIN, 0, arr1, arr2);
        return ans >= INT_MAX/2? -1: ans;
    }
};