void solve(Node* root, int k , int node, vector<int> path, int &ans ){
    
    if(root == NULL){
        return;
    }
    
    
    
    path.push_back(root->data);
    
    solve(root->left, k, node, path, ans);
    solve(root->right, k, node, path, ans);
    
    if(root->data == node){
        int size = path.size();
        
        if(size - 1 < k){
            ans = -1;
        }
        else{
            ans = path[size - k - 1];    
        }
        
        
    }
    
    path.pop_back();
    
    
    
    
    
}




int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    int ans = -1;
    
    if(root->data == node){
        return -1;
    }
    
    solve(root, k, node, path, ans);
    
    
    return ans;
    
}