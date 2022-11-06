#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

bool checkCircular(Node* head){
    //empty list
    if(head==NULL){
        return true;
    }
    
    Node* temp = head->next;

    //check if temp is null or not and we reach back to null or not
    while(temp != NULL && temp!=head){

        temp = temp->next;

    }

    // check if temp is equating back to temp
    if(temp==head){
        return true;
    }

    //no means temp was null
    return false;

}

int main(){

    


    return 0;

}