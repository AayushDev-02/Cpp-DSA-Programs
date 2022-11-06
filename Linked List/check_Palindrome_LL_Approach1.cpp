//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include <vector>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    
    bool checkPalindorme(vector<int> arr){
        
        int start = 0;
        int end = arr.size()-1;
        bool ans =true;
        
        while(start<=end){
            if(arr[start] != arr[end]){
                return false;
            }
            
            start++;
            end--;
        }
        
        return ans;
        
    }
    
    
    
    bool isPalindrome(Node *head)
    {
        
        
        vector<int> arr;
        int i=0;
        while(head!=NULL){
            arr.push_back(head-> data);
            head = head-> next;
        }
        
        return checkPalindorme(arr);
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends