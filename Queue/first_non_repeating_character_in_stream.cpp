#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
using namespace std;

string FirstNonRepeating(string s){

    unordered_map<char, int> count;
    queue<int> q;

    string ans="";

    for(int i=0; i<s.length(); i++){

        char ch = s[i];

        count[ch]++;

        q.push(ch);


        while(!q.empty()){

            // repeating character
            if(count[q.front()]  > 1){
                q.pop();
            }
            else{

                ans.push_back(q.front());
                break;

            }

        }

        // we reach here in 2 conditions - either queue is empty or we break from the loop when it is a non repeating character

        // if queue is empty we insert the #

        if(q.empty()){
            ans.push_back('#');
        }
    }

    return ans;



}



// //{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution {
// 	public:
//     		string FirstNonRepeating(string A){
		    
// 		    unordered_map<char,int> count;
// 		    queue<int> q;
		    
// 		    string ans="";
		    
// 		    int len = A.length();
		    
// 		    for(int i=0; i<len; i++){
// 		        char ch = A[i];
		        
// 		      //  increase count
// 		        count[ch]++;
// 		      //  push in queue
// 		        q.push(ch);
		        
// 		        while(!q.empty()){
		            
// 		          //  repeating character
// 		            if(count[q.front()] > 1){
// 		                q.pop();
// 		            }
// 		          //  non repeating character mil gaya
// 		            else{
// 		                ans.push_back(q.front());
// 		                break;
// 		            }
// 		        }
		        
// 		        if(q.empty()){
// 		            ans.push_back('#');
// 		        }
// 		    }
		    
// 		    return ans;
		    
		    
		    
// 		}

// };

// //{ Driver Code Starts.
// int main(){
// 	int tc;
// 	cin >> tc;
// 	while(tc--){
// 		string A;
// 		cin >> A;
// 		Solution obj;
// 		string ans = obj.FirstNonRepeating(A);
// 		cout << ans << "\n";
// 	}
// 	return 0;
// }
// // } Driver Code Ends





// int main(){

// }