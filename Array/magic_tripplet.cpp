//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    
	    int n = nums.size();
	    int count=0;
	    
	    for(int i=0; i<n ; i++){
	        
	        int small = 0;
	        for(int j=0; j<i; j++){
	            
	            if(nums[i] > nums[j]){
	                small++;
	            }
	            
	        }
	        
	        int large = 0;
	        for(int j =i+1; j<n; j++){
	            if(nums[j] > nums[i]){
	                large++;
	            }
	        }
	        
	        
	        count+=small*large;
	    }
	    
	    return count;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends