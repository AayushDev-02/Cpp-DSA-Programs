#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}

Node *
buildTree(Node *root)
{

    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return root;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}

void inorder(Node* root){
    if(!root) return root;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right); 
}

void preorder(Node* root){
    if(!root) return root;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(!root) return NULL;

    postorder(root->left);
    postorder(root->right);
    cout << root->data <<  " ";
}

void createTreeFromLevelOrder(Node* root){
    queue<Node*> q;

    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

//zig zag traversal
vector<int> zigzagTraversal(Node* root){

    vector<int> ans;
    if(root == NULL) return ans;

    zigzagTraversal(root == NULL){
        return ans;
    }
    
    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        
        vector<int> temp(q.size());

        for(int i=0; i<q.size(); i++){
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : q.size() - 1- i;
            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }

        leftToRight = !leftToRight;

        for(auto i: temp){
            ans.push_back(i);
        }

    }

    return ans;

}

void 

vector<int> verticalTraversal(Node* root){

    int level = 0;
    vector<int> ans;
   
    queue<pair<Node*, pair<int,int>>> q;

    q.push(root);

    while(!q.empty()){

    } 

}

int main()
{

    Node *root = NULL;
    root = buildTree(root);

    return 0;
}