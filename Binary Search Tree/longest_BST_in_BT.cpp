class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    info solve(Node* root, int &ans){
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }
        
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        
        info curr;
        curr.size = left.size + right.size + 1;
        curr.maxi = max(root->data, right.maxi);
        curr.mini = min(root->data, left.mini);
        
        if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
            curr.isBST = true;
        }else{
            curr.isBST = false;
        }
        
        // answer update
        if(curr.isBST){
            ans = max(ans, curr.size);
        }
        
        return curr;
    }
    
    int largestBst(Node *root)
    {
    	int ans=0;
    	info temp = solve(root, ans);
    	
    	return ans;
    }
};