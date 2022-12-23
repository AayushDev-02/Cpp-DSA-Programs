void solve(TreeNode<int>* root, vector<int> &ans ){
    if(root == NULL){
        return;
    }
    
    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    solve(root, ans);
    
    TreeNode<int>* newRoot = new TreeNode<int>(ans[0]);
    TreeNode<int>* curr = newRoot;
    
//     2nd step
    for(int i=1; i<ans.size(); i++){
        TreeNode<int>* temp = new TreeNode<int>(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    
//     3rd step
    curr ->left = NULL;
    curr->right = NULL;
    
    return newRoot;
    
}