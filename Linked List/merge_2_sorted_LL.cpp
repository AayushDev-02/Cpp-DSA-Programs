#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* solve(Node<int>* first, Node<int>* second){
    
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    
    Node<int>* prev= first;
    Node<int>* curr = first->next;
    
    Node<int>* temp = second;
    Node<int>* forward = temp->next;
    
    while(curr!=NULL && temp!=NULL)
    {
        int value = temp->data;
        int pvalue = prev->data;
        int cvalue = curr->data;
        
        if(value >= pvalue && value <= cvalue){
            
            forward = temp -> next;
            prev -> next = temp;
            temp->next = curr;
            
            prev= temp;
            temp = forward;
         }
        else{
            prev = curr;
            curr = curr->next;
            
            if(curr==NULL){
                prev->next = temp;
                return first;
            }
        }
    }
    
    return first;
}



Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL ){
        return second;
    }
    
    if(second == NULL){
        return first;
    }
    
    if(first ->data <= second->data){
        return solve(first,second);
    }else{
        return solve(second, first);
    }
}
