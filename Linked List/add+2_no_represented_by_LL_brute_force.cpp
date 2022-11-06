
//THIS APPROACH WILL NOT PASS ALL CASES AS THE VALUES WILL OVERLAP THE RANGE OF DATA TYPE

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{  
    
    private:
    Node* reverse(Node* &head){
        Node* prev =NULL;
        Node* curr = head;
        Node* forward = NULL;
        
        while(curr!=NULL){
            
            forward = curr->next;
            curr-> next = prev;
            prev = curr;
            curr = forward;
            
        }
        
        return prev;
        
    }
    
    void insertAtTail(Node* &tail, int d){
        
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = temp;
        
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        long long sum1=0;
        // int i=0;
        Node* temp = first;
        while(temp!=NULL){
            sum1 = sum1 * 10 + temp->data;
            temp = temp -> next;
        }
        
        // cout << sum1 << endl;


        long long sum2=0;
        temp = second;
    
        while(temp!=NULL){

            sum2 = sum2*10+temp->data;
            temp = temp -> next;

        }
        
        // cout << sum2 << endl;
        long long  ans = sum1+sum2;
        
        // cout << ans << endl;

        Node* final = new Node(-1);
        Node* finalTail = final;

        while(ans>0){

            insertAtTail(finalTail, ans%10);
            ans = ans/10;
            // cout <<"ans " <<  ans << " ";

        }

        final = reverse(final -> next);

        return final;




    }

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends