#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string str, int index, vector<string>& ans){

    //base case
    if(index >= str.length()){
        
        ans.push_back(ouput);
        return;
    }

    //Recursive relation

    for(int j = index; i< str.length();j++){
        swap(str[index], str[j]);                   // - this will swap each index to first or index value
        solve(str, output, index+1, ans);

        //backtracking
        swap(str[index], str[j]);                   // - returning to original string to solve for next index
        

    }


}



vector<vector<int>> permute(string& str) {

    vector<string> ans;
    int index = 0;
        
    solve(str, index, ans );
    
    return ans;
}

int main(){

    vector<int> nums{1,2,3};

    vector<vector<int>> ans = permute(nums);

    return 0;
}