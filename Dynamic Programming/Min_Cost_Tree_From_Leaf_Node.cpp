class Solution {
public:

    int solRec(vector<int> &arr, map<pair<int,int> , int> &maxi, int left, int right){

        //base case
        if(left == right) {
            //leaf node - > since all the elements are leaf nodes in the array, if we have a single element it will be leaf node. Also we only consider non leaf node sum, thus return 0;
            return 0;
        }

        int ans = INT_MAX;

        for(int i=left; i<right; i++){
            int leftAns = solRec(arr, maxi, left, i);
            int rightAns = solRec(arr, maxi, i+1, right);

            ans = min(ans, ( maxi[{left, i}] * maxi[{i+1, right}] ) + leftAns + rightAns );
        }

        return ans;

    }

    int solMemoization(vector<int> &arr, map<pair<int,int> , int> &maxi, int left, int right, vector<vector<int>> &dp){

        //base case
        if(left == right) {
            return 0;
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = INT_MAX;

        for(int i=left; i<right; i++){
            int leftAns = solMemoization(arr, maxi, left, i, dp);
            int rightAns = solMemoization(arr, maxi, i+1, right, dp);

            ans = min(ans, ( maxi[{left, i}] * maxi[{i+1, right}] ) + leftAns + rightAns );
        }
        dp[left][right] = ans;
        return ans;

    }

    int solTabulation(vector<int> &arr, map<pair<int,int> , int> &maxi){
        
        int n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int left = n-1; left>=0; left--){
            for(int right = 0; right <= n-1; right++){
                
                if(left == right){
                    continue;
                } 
                else{
                    int ans = INT_MAX;

                    for(int i=left; i<right; i++){
                        int leftAns = dp[left][i];
                        int rightAns = dp[i+1][right];

                        ans = min(ans, ( maxi[{left, i}] * maxi[{i+1, right}] ) + leftAns + rightAns );
                    }
                    dp[left][right] = ans;
                }

            }
        }

        return dp[0][n-1];
    }




    int mctFromLeafValues(vector<int>& arr) {
        
        map<pair<int,int> , int> maxi;

        //precompute max of range in map
        for(int i=0; i<arr.size(); i++){
            maxi[{i,i}] = arr[i];

            for(int j= i+1; j<arr.size(); j++){
                maxi[{i,j}] = max( arr[j], maxi[{i, j-1}] );    // max of curr and prev stored element
            }
        }

        int n = arr.size();
        // int ans = solRec(arr, maxi, 0, n-1);
        
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // int ans = solMemoization(arr, maxi, 0, n-1 , dp);

        int ans = solTabulation(arr, maxi);
        return ans;
    }
};