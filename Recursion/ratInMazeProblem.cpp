//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    private:
    
    //checking 3 conditions to move to x,y cell 
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m){
        
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }else{
            return false;
        }
        
    }
    
    
    
    
    
    
    
    
    void solve(vector<vector<int>> &m, int n , vector<string>& ans , int x , int y , vector<vector<int>> visited , string path ){
        
        
        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        //we have reached x,y position in m matrix - therefore mark as true in visited in visited matrix
        visited[x][y] = 1;
        
        //4 choiced - D L R U
        
        // -------------------------------------------------- D O W N ----------------------------------------------
        //down
        int newx = x+1;
        int newy = y;
        
        if(isSafe(newx,newy, n ,visited, m)){
            path.push_back('D');
            solve(m,n,ans,newx, newy, visited, path);
            
            path.pop_back(); // backtracking
        }
        
        
        // -------------------------------------------------- L E F T ----------------------------------------------
        //left
        newx = x;
        newy = y-1;
        
        if(isSafe(newx,newy, n ,visited, m)){
            path.push_back('L');
            solve(m,n,ans,newx, newy, visited, path);
            
            path.pop_back(); // backtracking
        }
        
        // -------------------------------------------------- R I G H T ----------------------------------------------
        //right
        newx = x;
        newy = y+1;
        
        if(isSafe(newx,newy, n ,visited, m)){
            path.push_back('R');
            solve(m,n,ans,newx, newy, visited, path);
            
            path.pop_back(); // backtracking
        }
        
        // -------------------------------------------------- U P ----------------------------------------------
        //up
        newx = x-1;
        newy = y;
        
        if(isSafe(newx,newy, n ,visited, m)){
            path.push_back('U');
            solve(m,n,ans,newx, newy, visited, path);
            
            path.pop_back(); // backtracking
        }
        
        
        
        visited[x][y] = 0; // backtracting after one path is found 
    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;

        //when source index has 0 value
        if(m[0][0] == 0){
            return ans;
        }
        
        //source index
        int src_x=0;
        int src_y=0;
        
        //movement path
        string path = "";
        
        //copy of m - 2d array called visited
        vector<vector<int>> visited=m;

        //initilize with 0
        for(int i=0;i<n;i++){
            for(int j=0; j<n ;j++){
                visited[i][j]=0;
            }
        }
        
        solve(m,n, ans ,src_x, src_y, visited, path);

        //sorted to print ans in lexicographically increasing order
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends