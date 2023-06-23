#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
}


void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);

    temp->next = head;
    head = temp;

}

void printLL(Node* &head){

    Node* temp = head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* head, int posi, int data){

    Node* temp = head;
    int i = 1;
    while(i<=posi){
        temp = temp->next;
        i++;
    }

    Node* newNode = new Node(data);
    if(temp->next){
        newNode -> next = temp->next;
        temp -> next = newNode;
    }
    else{
        temp->next = newNode;
    }

}

void deleteNode(Node* &head, int posi){

    if(posi == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);
    }

    Node* prev = NULL;
    Node* curr = head;

    int i = 1;
    while(i<posi){
        prev = curr;
        curr = curr->next;

        i++;
    }

    prev->next = curr->next;
    curr->next = NULL;

    delete curr;
}

int main(){
    return 0;
}