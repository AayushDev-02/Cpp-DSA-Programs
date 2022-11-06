    #include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    //constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;

        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout << "Memory free for node with data: " << val << endl; 


    }
};

//insertion - at head

void insertAtHead(Node* &head,Node* &tail, int d){
    //empty list
    if(head==NULL){
        Node * temp = new Node(d);
        head= temp;
        tail=temp;
    }else{
         Node* temp = new Node(d);

        temp->next=head;
        head->prev = temp;

        temp->prev = NULL;

    head = temp;

    }

}

void insertAtTail(Node* &head, Node* &tail, int d){

    //empty list
    if(head==NULL){
        Node * temp = new Node(d);
        head= temp;
        tail=temp;
    }else{

        Node* temp = new Node(d);

        tail->next = temp;
        temp->prev = tail;
        tail =temp;
    }



}

void insertAtPosition(Node * &head, Node* &tail,int position, int d){
    if(position == 1){
        insertAtHead(head,tail, d);
        return;
    }

    Node * temp = head;
    int cnt=1;
    while(cnt< position-1){
        cnt++;
        temp = temp->next;
    }

    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node * nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;


}

void deleteNode(Node* &head, int position ){

    //deleting first or start node
    if(position ==1){

        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{

        //deleting any middle node or last node

        Node * curr = head;
        Node * p = NULL;

        int cnt=1;
        while(cnt < position){

            p = curr;
            curr = curr->next;
            cnt++;

        }

        curr->prev = NULL;
        p->next = curr->next;
        curr->next = NULL;
        delete curr;
    }





}




// traversing a linked  list
void print(Node* &head){

    Node * temp = head;

    while(temp !=NULL){

        cout << temp->data << " ";
        temp= temp->next;

    }

    cout << endl;

}
//gives lenght of the linked list
int getLength(Node * &head){

    Node* temp = head;
    int cnt=0;

    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }

    return cnt;



} 



int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    cout << "The lenght of the Linked list is : " << getLength(head) << endl;
    
    insertAtHead(head, tail, 5);
    print(head);

    insertAtHead(head, tail,  4);
    print(head);

    insertAtHead(head,tail, 3);
    print(head);

    insertAtHead(head,tail, 2);
    print(head);

    insertAtHead(head,tail, 1);
    print(head);

    insertAtTail(head,tail, 20);
    print(head);

    insertAtPosition(head, tail, 8, 40);
    print(head);

    insertAtPosition(head, tail, 1, 0);
    print(head);

    insertAtPosition(head, tail, 6, 6);
    print(head);

    //middle element
    deleteNode(head, 6);
    print(head);

    //first node
    deleteNode(head, 1);
    print(head);

    //last node
    deleteNode(head, 8);
    print(head);
    







    return 0;
}