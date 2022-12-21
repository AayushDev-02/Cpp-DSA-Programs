void solve(Node* root, int &i, int k, int &ans){
        if(root == NULL){
            return;
        }
        
        solve(root->left,i,k, ans);
        
        i++;
        if(i == k){
            ans = root->data;
            return;
        }
        
        solve(root->right, i , k , ans);
    }
  
  
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int ans=-1;
        int i=0;
        solve(root,i,K, ans);
        
        if(ans == -1){
            return -1;
        }
        
        return ans;
    }