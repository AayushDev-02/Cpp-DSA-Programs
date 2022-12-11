#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        
        int data;
        Node* left;
        Node* right;
        
    // constructor
    Node(int data){

        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};

// function to create a tree
Node* buildTree(Node* root){

    int data; 
    cout << "Enter the data: " << endl;
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    // left part
    cout << "Enter data for inserting in left of "<< data <<" : " << endl;
    root->left = buildTree( root->left );

    // right part
    cout << " Enter data for inserting in right: "<< data << " : " << endl;
    root->right = buildTree( root->right );

    return root;

}


// LEVEL ORDER TRAVERSAL - Also Known as  - BREADTH FIRST SEARCH
void levelOrderTraversal( Node* root ){

    queue<Node*> q;

    // inserting root elememt
    q.push(root);

    q.push(NULL);       // for seperation

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        // for seperation
        if(temp == NULL){       //poorana level complete traverse ho chuka h
            cout << endl;

            if(!q.empty()){     // queue still has some child nodes
                q.push(NULL); 
            }
        }
        else{

            cout << temp->data << " ";


            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }



    }

}


void buildFromLevelOrder(Node* &root){

    queue<Node*> q;

    cout << "Enter data for root : " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << " Enter the left node for " << temp->data << " : " << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){

            temp -> left = new Node(leftData);
            q.push(temp->left);

        } 

        cout << " Enter the right node for " << temp->data << " : " << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){

            temp -> right = new Node(rightData);
            q.push(temp->right);

        } 
    }
}


int main(){

    Node* root = NULL;
    buildFromLevelOrder(root);

    cout << endl; 

    levelOrderTraversal(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1


    return 0;
}