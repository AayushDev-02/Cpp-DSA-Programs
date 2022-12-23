void solve(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    
    solve(root->left, arr);
    arr.push_back(root->data);
    solve(root->right, arr);
}

Node* inorderToBST(int start, int end, vector<int> &arr){
    // base case
    if(start > end){
        return NULL;
    }
    
    int mid = start+(end-start)/2;
    Node* root = new Node(arr[mid]);
    
    root->left = inorderToBST(start, mid-1, arr);
    root->right = inorderToBST(mid+1, end, arr);
    
    return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<int>arr;
	solve(root, arr);
	
	return inorderToBST(0,arr.size()-1,arr);
	
}
