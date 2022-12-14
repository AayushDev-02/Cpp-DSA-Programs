void solve(Node* root, int level, vector<int> &ans){
    
    if(root == NULL){
        return ;
    }
    
    // we entered into a new level
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    // left
    solve(root->left, level+1, ans );
    // right 
    solve(root->right, level+1, ans);
    
}



vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, 0, ans);
   
   return ans;
}