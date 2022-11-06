//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
    
// An utility function to merge two sorted linked lists
Node* merge(Node* first, Node* second){
    
    
    // If first linked list is empty then second is the answer
    if(first == NULL){
        return second;
    }
    // If second linked list is empty then first is the result
    if(second == NULL){
        return first;
    }
    
    // Compare the data members of the two linked lists and put the larger one in the result
    Node* ans ;
    
    if(first -> data < second -> data){
        ans = first;
        ans -> bottom = merge(first -> bottom, second);
    }else{
        ans = second;
        ans -> bottom = merge(first, second -> bottom);
    }
    
    ans  -> next = NULL;
    return ans;
    
    
}
    
Node *flatten(Node *head)
{
    
    // Base Cases
   if(head == NULL || head -> next == NULL){
       return head;
   }
   
   // Recur for list on right
   head -> next = flatten(head -> next);
   
   // Now merge
   head = merge(head , head -> next);
   
   // Return the root
    // it will be in turn merged with its left
   return head;
   
   
}

