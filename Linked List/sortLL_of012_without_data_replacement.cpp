#include <iostream>
using namespace std;

void insertAtTail(Node* &tail, int d){
    
    Node* temp = new Node(d);

    tail->next = temp;
    tail= temp;

}




Node* sort(Node* head){

    if(head==NULL){
        return NULL;
    }

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr =head;

    //create seperate list 0s,1s,2s
    while(curr!=NULL){

        if(curr->data == 0){
            insertAtTail(zeroTail,0);
        }else if(curr->data == 1){
            insertAtTail(oneTail,1);
        }else{
            insertAtTail(twoTail,2);

        }

        curr = curr->next;
    }

    //merge the 3 linked list
    
    if(oneHead-> next != NULL){
        //one ki list is not empty
        zeroTail->next = oneHead->next;

    }else{
        //one ki list is empty
        zeroTail -> next = twoHead->next;
    }
    

    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setup head
    head = zeroHead->next;

    //delete dummy node
    delete oneHead;
    delete twoHead;

    return head;

}



int main(){
    return 0;
}