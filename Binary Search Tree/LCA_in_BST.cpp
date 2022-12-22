
// Recursive appraoch
Node* LCA(Node *root, int n1, int n2)
{
   if(root == NULL){
        return NULL;
    }
    
    if(root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    
    if(root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    
    return root;
}

//Iterative Approach

Node* LCA(Node *root, int n1, int n2)
{
   Node* temp = root;
   Node* ans;
   
   while(temp!=NULL){
       if(temp->data < n1 && temp->data < n2){
           temp = temp->right;
       }
       else if(temp->data > n1 && temp->data > n2){
           temp = temp->left;
       }
       else {
           ans = temp;
           break;
       }
   }
   
   return ans;
}
