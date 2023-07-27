#include <iostream>
using namespace std;

class Node {
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

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

bool searchInBST(Node* root, int x){
    if(root == NULL){
        return;
    }

    if(root->data == x){
        return true;
    }

    if(root->data > x){
        return searchInBST(root->left, x);
    }
    else{
        return searchInBST(root->right, x);
    }
}

Node* deleteFromBST(Node* root, int data){

    if(root == NULL) return NULL;

    if(root->data == data){

        //0child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            //2 child

            int maxValue = INT_MIN;

            Node* temp = root;

            while(temp->left){
                temp = tmep->left;
            }
            maxValue = temp->data;

            root->data = maxValue;
            
            root->left = deleteFromBST(root->left, maxValue);
            return root;
        }

    }

    else if(root->data > data){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }

}
int main(){





    return 0;
}