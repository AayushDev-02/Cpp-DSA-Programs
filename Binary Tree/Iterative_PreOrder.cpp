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

vector<int> iterativePreOrder(Node* root){
    
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* topNode = s.top();
        s.pop();
        ans.push_back(topNode -> data);

        if(topNode->right){
            s.push(topNode->right);
        }

        if(topNode->left){
            s.push(topNode->left);
        }

    }

    return ans;
    

}

int main(){




    return 0;
}