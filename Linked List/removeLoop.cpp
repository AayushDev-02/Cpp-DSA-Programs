#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor   
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor - for deletion function
    ~Node(){
        int value = this-> data;

        //code to free memory
        if(this-> next != NULL){
            delete next;
            this->next = NULL;

        }

        cout << "Memory is free for node with data" << value << endl; 
    }

};

void insertAtTail(Node * &tail, int d){

    //new node created
    Node *temp = new Node(d);

    tail -> next = temp;    //tail node will point to new node
    tail = temp;            // updating tail element


}

Node* floydDetect(Node* head){

    if(head==NULL){
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && slow!=NULL){
        fast = fast->next;

        if(fast!=NULL){
            fast = fast->next;
          }

        slow = slow->next;

        if(fast==slow){
            return slow;
        }
    }

    return NULL;
}


Node* startNode(Node * head){

    if(head==NULL){
        return NULL;
    }

    Node* intersection = floydDetect(head);

    if(intersection == NULL){
        return NULL;
    }

    Node* slow = head;

    while(slow!=intersection){

        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;

}


void removeLoop(Node *head){
    if(head == NULL){
        return;
    }

    Node* startOfLoop = startNode(head);
    if(startNode == NULL){
        return;
    }

    Node* temp = startOfLoop;

    while(temp->next != startOfLoop ){
        temp = temp->next;
    }

    temp -> next = NULL;
}

void print(Node* &head){
    
    //create a temp node
    Node * temp = head;

    while(temp !=NULL){
        
        //printing current node data
        cout << temp->data << " ";

        //temp ko aage badhado
        temp = temp -> next;
    }

    cout << endl;

}

int main(){

    Node* node1 = new Node(10);

    // cout << node1->data << endl;
    // cout << node1->next << endl;

    //head pointing to node
    Node * head = node1;
    //creating tail
    Node * tail = node1;
    
    //inserting at head
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail,20);
    insertAtTail(tail, 22);
    // tail->next = head->next ;  

    // print(head);

    if(startNode(head)!=NULL){
        cout << "STARTING NODE OF LOOP IN LINKED LIST IS: " << startNode(head) ->data << endl;
    }else{
        cout << "No loop is pesent!" << endl;
    }

    
    removeLoop(head);
    print(head);


    return 0;



}