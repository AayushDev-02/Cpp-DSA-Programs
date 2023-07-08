class Solution {
public:

    int solRec(string a, string b, int i, int j){

        if(i == a.length() || j == b.length()){
            return 0;
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = solRec(a,b,i+1, j+1) + 1;
        }
        else{
            ans =  max(solRec(a,b,i,j+1) , solRec(a,b,i+1, j));
        }

        return ans;
    }

    int solMemoization(string &a, string &b, int i, int j, vector<vector<int>> &dp){

        if(i == a.length() || j == b.length()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        
        if(a[i] == b[j]){
            ans = solMemoization(a,b,i+1, j+1, dp) + 1;
        }
        else{
            ans =  max(solMemoization(a,b,i,j+1, dp) , solMemoization(a,b,i+1, j, dp));
        }

        dp[i][j] = ans;
        return ans;
    }
    
    int solTabulation(string a, string b){
        vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1, 0));

        for(int i = a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){

                int ans = 0;
        
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1] + 1;
                }
                else{
                    ans =  max( dp[i][j+1] , dp[i+1][j] );
                }

                dp[i][j] = ans;

            }
        }
        return dp[0][0];
    }

    int spaceOpt(string a, string b) {

        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){

                int ans = 0;
        
                if(a[i] == b[j]){
                    ans = next[j+1] + 1;
                }
                else{
                    ans =  max( curr[j+1] , next[j] );
                }

                curr[j] = ans;

            }
            next = curr;
        }
        return next[0];

    }


    int longestPalindromeSubseq(string s) {
        
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;

        // int ans = solRec(first, second, 0, 0);

        // vector<vector<int>> dp(first.length()+1, vector<int> (second.length()+1, -1));
        // int ans = solMemoization(first, second, 0, 0, dp);

        // int ans = solTabulation(first, second);

        int ans = spaceOpt(first, second);
        return ans;
    }
};