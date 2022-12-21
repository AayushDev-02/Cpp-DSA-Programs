
// RECURSIVE APPROACH - TC:  O(log n) => O(n) in worst case, SC: O(height)
bool search(Node* root, int x) {
    if(root == NULL){
        return false;
    }
    
    int curr = root->data;
    if(curr == x){
        return true;
    }
    else if( curr < x){
        return search(root->right, x);
    }
    else{
        return search(root->left, x);
    }
    
    return false;
}

// ITERATIVE APPROACH (better) - reduce the SC to 0(1)
bool search(Node* root, int x) {
    
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        
        if(temp->data > x){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    
    return false;
}