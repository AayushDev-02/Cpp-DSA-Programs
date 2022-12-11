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

// POSTORDER TRAVERSAL - LRN -----------------------------------------------------------------------

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



// ------------------------------------------------------------------------------------------------


int main(){

    Node* root = NULL;
    
    root = buildTree(root); 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << endl;

    cout << "Postorder Traversal is : ";
    postorder(root);


    return 0;
}