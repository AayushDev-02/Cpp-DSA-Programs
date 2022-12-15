Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL){
           return NULL;
       }
       
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
        //   left
       Node* leftAns = lca(root->left, n1,n2);
        // right   
       Node* rightAns = lca(root->right, n1,n2);
       
       if(leftAns == NULL && rightAns == NULL){
           return NULL;
       }
       
       else if(leftAns == NULL && rightAns != NULL ){
           return rightAns;
       }
       
       else if (leftAns != NULL && rightAns == NULL){
           return leftAns;
       }
       
       else if(leftAns != NULL && rightAns!=NULL){
           return root;
       }
       
       
    }