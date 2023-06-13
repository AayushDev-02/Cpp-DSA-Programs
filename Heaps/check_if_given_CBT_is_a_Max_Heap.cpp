#include <iostream>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}
pair<bool, int> validateHeap(Node* root){
    if(root == NULL){
        return {true, INT_MIN};
    }

    if(root->left == NULL && root->right == NULL){
        return {true, root->data};
    }

    auto left = validateHeap(root->left);
    auto right = validateHeap(root->right);

    pair<bool , int> ans;
    ans.first = left.first && right.first && (left.second < root->data && right.second < root->data);

    if(ans.first){
        ans.second = root->data;
    }
    else{
        ans.second = INT_MAX;
    }


    return ans;

}

bool solve(Node* root){
    pair<bool, int> ans = validateHeap(Node* root);
    return ans.first;
}

int main(){
    
}