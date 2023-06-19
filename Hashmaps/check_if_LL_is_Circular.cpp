#include <iostream>
#include <unordered_map>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
}

bool checkCircular(Node* root){
    
    unordered_map<Node*, bool> visited;

    Node* temp  = root;
    while(temp != NULL){
        if(visited.find(temp) != visited.end()){
            visited[temp] = true;
        }
        else{
            return true;
        }

        temp = temp->next;
    }

    return false;

}

int main(){

    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = head;

    bool ans = checkCircularLL(head);

    if(ans){
        cout << "Yes the LL is circular" << endl;
    }
    else cout << "Not a circular LL" << endl;


    return 0;
}
