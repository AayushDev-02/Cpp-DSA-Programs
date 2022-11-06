#include <iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int val=this->data;

        while(this->next !=NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};

void insertNode(Node * &tail, int element, int d){


    //case 1 - Empty List
    if(tail == NULL){

        Node* newNode = new Node(d);
        tail=newNode;
        newNode->next = newNode;

    }else{
        // non empty list
        //assuming that the node is presetnt in the linked list

        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }

        //element found -> current is representing element wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

    }
}

// Deletion --------------------------------------------------------------------
void deleteNode(Node* &tail, int element){

    if(tail == NULL){
        cout << "List is empty , please check again" << endl;
        return;

    }else{

        //non empty case
        //assuming that the element is present in the linked list

        Node* prev = tail;
        Node* curr = prev->next;

        while(curr ->data != element){
            prev = curr;    
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked List
        if(curr == prev){
            tail=NULL;
        
        }   // >=2 nodes
        else if(tail == curr){
            tail = prev; 
        }


        //when tail is also at curr we need to change it as curr will be deleted
        

        curr->next=NULL;
        delete curr;

    }


}
















void print(Node* &tail){

    if(tail==NULL){
        cout << "List is empty ! " << endl;
        return;
    }

    Node* temp = tail;
    //method 1

    // cout << tail->data << " ";

    // while(temp -> next != tail){

    //     cout << temp->data << " ";
    //     temp = temp-> next;

    // }

    // cout << endl;

    //method 2 -- using do while loop because of its property of running at least 1 time  - as it executes before checking the condition
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while (temp != tail    );

    cout << endl;
    
}


int main(){

    Node* tail = NULL;

    //empty list m insert kar rahe  h
    insertNode(tail ,5, 3);
    print(tail);

    // //inserting at the end
    // insertNode(tail ,3, 5);
    // print(tail);

    // insertNode(tail ,5, 7);
    // print(tail);

    // insertNode(tail ,7, 9);
    // print(tail);

    // //inserting at the middle
    // insertNode(tail, 5, 6);
    // print(tail);

    // //inserting at first node
    // insertNode(tail, 9, 10);
    // print(tail);

    // //deleting a node
    // deleteNode(tail,6);
    // print(tail);

    //deleting a single node
    deleteNode(tail, 3);
    print(tail);

    
    return 0;
}