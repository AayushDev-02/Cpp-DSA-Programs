#include <iostream>
using namespace std;

//creating a LL node
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

//insertion function

void insertAtHead(Node* &head, int d){

    //new node created
    Node *temp = new Node(d);

    temp->next = head;  // new node pointing to head
    head = temp;        // changing or updating the head pointer

}

//inset at tail func
void insertAtTail(Node * &tail, int d){

    //new node created
    Node *temp = new Node(d);

    tail -> next = temp;    //tail node will point to new node
    tail = temp;            // updating tail element


}

//insert at a posiiton
void insertAtPosition(Node * &tail , Node * &head, int position, int d){

    //insert at start
    if(position==1){
        insertAtHead(head, d);
        return;
    }

    


    Node *temp = head;
    int cnt=1;

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    //checking for last position insertion
    if(temp->next==NULL){
        insertAtTail(tail, d);
    }

    //creating a node for d
    Node *nodeToInsert = new Node(d);
    

    nodeToInsert -> next = temp->next;
    temp->next = nodeToInsert;
}  


//deletion function - position
void deleteNode(int position, Node * &head){
    
    Node *temp = head;

    //deleting 1st node
    if(position == 1){
        
        head = head->next;

        //memory free of start node
        temp->next = NULL;
        delete temp;

    }else{          
        
        //deleting middle or last node
        Node * curr = head;
        Node * prev = NULL;

        int cnt = 1;
        while(cnt < position){

            prev= curr;
            curr = curr-> next;
            cnt++;
        }

        prev->next= curr -> next;
        curr->next = NULL;  
        delete curr;



            


    }
    
    
    

}






//printing a LL
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

    //creating a new node
    Node* node1 = new Node(10);

    cout << node1->data << endl;
    cout << node1->next << endl;

    //head pointing to node
    Node * head = node1;
    print(head);

    //creating tail
    Node * tail = node1;
    
    //inserting at head
    insertAtHead(head, 12);

    print(head);

    insertAtHead(head, 15);
    print(head);

    //inserting at tail
    insertAtTail(tail,20);
    print(head);


    //inserting at nth position
    insertAtPosition(tail, head, 3, 22);
    print(head);

    //inserting at 1st position
    insertAtPosition(tail, head, 1, 69);
    print(head);

    //inserting at last position
    insertAtPosition(tail, head, 7, 100);
    print(head);

    cout << endl;
    cout << head->data << endl;
    cout << tail->data << endl;
    cout << endl;

    //deleteing 1st node
    deleteNode(8,head);
    print(head);

    cout << endl;
    cout << head->data << endl;
    cout << tail->data << endl;
    cout << endl;
    

    return 0;
}