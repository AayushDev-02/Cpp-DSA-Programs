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
}

vector<int> iterativeInOrder(Node* root){

    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    stack<Node*> s;
    Node* temp = root;

    while(true){
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        else{
            if(s.empty()) break;
            temp = s.top();
            s.pop();
            ans.push_back(temp->data);
            temp = temp->right;

        }
    }

    return ans;


}