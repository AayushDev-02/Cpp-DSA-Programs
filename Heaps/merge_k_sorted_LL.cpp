#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL; 
        }
};


class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;   
        }
};


Node* mergeKList(vector<Node*> lists){

    //create a min heap of node* data type
    priority_queue<Node*, vector<Node*>, compare>> minHeap;

    //insert the heads in the given linked list into the heap
    int k = lists.size();

    if(k == 0) return NULL;

    for(int i=0; i<k; i++){
        if(lists[i]){
            minHeap.push(lists[i]);
        }
    }

    //now create the ans LL and add elements from the top of the heap
    Node* root = NULL;
    Node* temp = root;

    while(!minHeap.empty()){
        Node* topNode = minHeap.top();
        minHeap.pop();

        if(root == NULL){
            root = topNode;
            temp = topNode;
        }
        else{
            temp->next = topNode;
            temp = temp -> next;
        }

        if(topNode->next){
            minHeap.push(topNode->next);
        }
    }

    return root;

}
