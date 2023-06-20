class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";

        string x = strs[0];

        for(int i=0; i<x.length(); i++){
            char ch = x[i];

            for(int j=0; j<strs.size(); j++){
                if( strs[j].size() < i || strs[j][i] != ch){
                    return ans;
                }
            }
            ans+=ch;
        }

        return ans;
    }
};