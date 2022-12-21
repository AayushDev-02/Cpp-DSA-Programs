int solve(Node* root, int &i, int k ){
        // base case
        if(root == NULL){
            return -1;
        }
        
        // L
        int left = solve(root->left, i ,k);
        if(left != -1){
            return left;
        }
        
        // N
        i++;
        if(i==k){
            return root->data;
        }
        
        // R
        return solve(root->right, i, k); 
    }
  
  
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int i=0;
        int ans = solve(root,i,K);
        
        return ans;
    }