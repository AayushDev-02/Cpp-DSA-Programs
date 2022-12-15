void solve(Node* root, int k, int &count, vector<int> path){
        if(root == NULL){
            return;
        }
        
        path.push_back(root->data);
        
        // left
        solve(root->left, k, count, path);
        // right
        solve(root->right, k, count, path);
        
        // check for k sum
        int sum=0;
        int size = path.size();
        for(int i=size-1; i>=0; i--){
            sum+=path[i];
            
            if(sum == k){
                count++;
            }
        }
        
        // backtracking - removing the added node value when we move back to previous level
        path.pop_back();
    }
  
  
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        
        solve(root, k, count, path);
        
        return count;
    }