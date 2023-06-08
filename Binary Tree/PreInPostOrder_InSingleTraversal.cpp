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

void solve(Node* root, vector<int> &pre, vector<int> &in, vector<int> &post){

    if(root == NULL){
        return;
    }

    stack<pair<int,Node*>> s;
    s.push({root,1});

    while(!s.empty()){
        auto i = s.top();
        s.pop();

        if(i.second == 1){      // preorder condition
            pre.push_back(i.first->data);
            i.second++;
            s.push(i);

            if(i.first -> left){
                s.push({i.first->left, 1});
            }
        }
        else if(i.second == 2){     // inorder condition
            in.push_back(i.first->data);
            i.second++;
            s.push(i);

            if(i.first -> right){
                s.push({i.first->right, 1});
            }
        }
        else{   // postorder condition, do not push i back into the stack
            post.push_back(i.first->data);
        }
    }

    return;
}


int main(){



    return 0;
}