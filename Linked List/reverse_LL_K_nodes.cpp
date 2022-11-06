#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

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


// Node* kReverse(Node* head, int k) {
//     if(head==NULL){
//         return head;
//     }
//     //step 1 - reverse first k nodes
//     Node* prev =NULL;
//     Node* curr = head;
    
//     Node* forward=NULL;
//     int cnt=0;
//     while(cnt<k && curr!=NULL){
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//         cnt++;
//     }
    
// //     cout << "Forward value: " << forward->data << endl;
// //     cout << "Curr value : " << curr->data << endl;
    
//     //step 2 - Recursion dekh lega
//     if(forward!=NULL){
//         head->next = kReverse(forward, k);
//     }
       
//      //step 3-retrun head of reversed list
//     return prev;
// }