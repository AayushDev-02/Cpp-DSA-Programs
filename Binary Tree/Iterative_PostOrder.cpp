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

//using 2 stacks -- method 1
vector<int> iterativePostOrder1(){
    vector<int> ans;
    if(root = NULL){
        return ans;
    }

    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        s2.push(root);

        if(root->left){
            s1.push(root->left);
        }
        if(root->right){
            s1.push(root->right);
        }

    }

    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }

    return ans;
}

int main(){
    return 0;
}