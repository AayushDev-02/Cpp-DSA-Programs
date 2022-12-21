#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* insertIntoBST (Node* root, int data){

    // base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        // right part m insert karna h
        root->right = insertIntoBST(root->right, data);
    }
    else {
        // left part m insert karna h
        root->left = insertIntoBST(root->left, data);
    }
    
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

// IN ORDER - LNR
void inorder(Node* root){

    //base case
    if(root == NULL){
        return;
    }

    // L
    inorder(root->left);
    // N
    cout << root->data << " ";
    // R
    inorder(root->right);

}


// PRE ORDER - NLR
void preorder(Node* root){

    if(root == NULL){
        return;
    }

    // N
    cout << root->data << " ";
    // L
    preorder(root->left);
    // R
    preorder(root->right);

}

// POST ORDER - LRN
void postorder(Node* root){

    if(root == NULL){
        return;
    }

    // L
    postorder(root->left);
    // R
    postorder(root->right);
    // N
    cout << root->data << " ";

}


void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}



int main(){
    Node* root = NULL;

    cout << "Enter Data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Printing Inorder: " << endl;
    inorder(root);
    cout << endl;

    cout << endl << "Printing Preorder: " << endl;
    preorder(root);
    cout << endl;

    cout << endl << "Printing Postorder: " << endl;
    postorder(root);
    cout << endl << endl;

    return 0;
}