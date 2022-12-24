
int findCeil(Node* root, int input) {
    int ceil = -1;
    while(root){
        if(root->data == input){
            ceil = root->data;
            return ceil;
        }
        
        if(root->data > input){
            ceil = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    
    return ceil;
}