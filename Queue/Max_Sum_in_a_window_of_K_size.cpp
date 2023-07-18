//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int n){
        
        long ans = -1;
        long sum = 0;
        queue<int> q;
         
        //first k elements
        for(int i=0; i<k; i++){
            
            sum+=Arr[i];
            q.push(i);
        }
        
        ans = max(ans, sum);
        
        for(int i=k; i<n; i++){
            
            // remove the first elment which is out of window
            int val = Arr[q.front()];
            sum -= val;
            q.pop();
            
            //insert the new element
            q.push(i);
            sum += Arr[i];
            ans = max(ans, sum);
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends