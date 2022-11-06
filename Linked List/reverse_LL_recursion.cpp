#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


// Approach 2
Node* reverse1(Node* &head){

    if(head==NULL || head->next == NULL){
        return head;
    }

    Node* chotaHead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotaHead;

}




// Approach 1
void reverse(Node* &head, Node* &curr, Node* &prev){

    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;   
    reverse(head, forward, curr);

    curr->next = prev;

}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    
    
    // Method 1
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
   
    reverse(head, curr, prev);

    // Method2
    // return reverse1(head);


    return head;
    
    
}