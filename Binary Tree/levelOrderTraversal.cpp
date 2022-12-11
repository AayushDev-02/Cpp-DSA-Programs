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



int main(){

    Node* root = NULL;
    
    root = buildTree(root); 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order traversal
    cout << "Printing the level order traversal output : " << endl;
    levelOrderTraversal(root);


    return 0;
}