//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        int missing;
        int repeat;
        int i=0;
        while( i<n ){
            if( arr[i] == arr[arr[i] - 1] ){
                i++;
            }else{
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] != i+1){
                missing = i+1;
                repeat = arr[i];
            }
        }
        
        int* ans = new int[2];
        ans[1] = missing;
        ans[0] = repeat;
        
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
        int a[n];
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