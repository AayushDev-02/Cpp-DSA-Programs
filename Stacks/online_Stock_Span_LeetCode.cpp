#include <iostream>
using namespace std;



class StockSpanner {
public:
    
    vector<int> arr;
    stack<int> s;
    int i=0;
        
    
    StockSpanner() {

    }
    
    int next(int price) {
        arr.push_back(price);
        int res;
        
        while(!s.empty() && price >= arr[s.top()]){
            s.pop();
        }
        
        
        if(s.empty()){
            res = i+1;
        }else {
            res = i-s.top();
        }
        
        s.push(i++);
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// GEEKFORGEEKS: ---------------------------------------------------------------------------------------------

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    vector <int> higherPrevIndex(int price[], int n){
        
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<n; i++){
            
            int curr = price[i];
            // cout << price[s.top()] << " " ;
            // cout << curr << endl;
            
            while(s.top()!=-1 && price[s.top()] <= curr){
                s.pop();
                // cout << s.top() << endl;
            }
            // cout << s.top() << endl;
            ans[i] = s.top();
            s.push(i);
            
        }
        
        return ans;
        
    }
    
    
    
    
    
    
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       
        vector<int> left(n);
        left = higherPrevIndex(price, n);
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            
            // cout << left[i] << endl;
            
            ans[i] = i - left[i];
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
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends