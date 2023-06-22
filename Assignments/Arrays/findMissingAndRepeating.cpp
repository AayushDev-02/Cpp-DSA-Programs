//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int i=0;
        while(i<n){
            
            int index = arr[i] - 1;
            if(arr[index] != arr[i]){
                swap(arr[i], arr[index]);
            }
            else{
                i++;
            }
            
        }
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(arr[i] != i+1){
                ans.push_back(arr[i]);
                ans.push_back(i+1);
            }
        }
        
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends