#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

// int getLength(Node* head){
//    int cnt=0;
//     while(head!=NULL){
//         cnt++;
//         head = head->next;
//     }
//     return cnt;
// }

Node* getMiddle(Node* head){
    if (head==NULL || head->next == NULL){
        return head;
    }
    
    if(head -> next ->next == NULL){
        return head->next;
    }
    Node* fast = head->next;
    Node* slow = head; 
    
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
       
        
        slow = slow->next;
    }
    
    return slow;
}


Node *findMiddle(Node *head) {
    //Approach 1
//     int len = getLength(head);
    
//     int ans = len/2 + 1;
//     Node* temp = head;
//     len=1;
//     while(len<ans){
//         len++;
//         temp = temp->next;
//     }
    
//     return temp;
    
    //Approach 2 - Better Optimised Approach
    return getMiddle(head);
}