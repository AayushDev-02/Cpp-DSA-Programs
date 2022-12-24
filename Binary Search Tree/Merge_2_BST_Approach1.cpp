void solve(TreeNode<int>* root, vector<int> &arr){
        if(root == NULL){
            return;
        }
        
        solve(root->left, arr);
        arr.push_back(root->data);
        solve(root->right, arr);
    }
    
    vector<int> mergeArrays(vector<int> a , vector<int> b){
        vector<int> ans(a.size() + b.size());
        
        int i =0;
        int j = 0;
        int k = 0;
        while(i<a.size() && j<b.size()){
            if(a[i] < b[j]){
                ans[k++] = a[i];
                i++;
            }else{
                ans[k++] = b[j];
                j++;
            }
        }
        
        while(i<a.size()){
            ans[k++] = a[i];
            i++;
        }
        
        while(j<b.size()){
            ans[k++] = b[j];
            j++;
        }
        
        return ans;
    }
    
    TreeNode<int>* inBST(vector<int> &arr, int start, int end ){
        if(start > end){
            return NULL;
        }
        
        int mid = start+(end - start)/2;
        
        TreeNode<int>* root = new TreeNode<int>(arr[mid]);

        root->left = inBST(arr, start, mid-1);
        root->right = inBST(arr, mid+1, end);
        
        return root;
        
    }
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // STEP 1 : store inorder 
       vector<int> bst1;
       vector<int> bst2;
       
       solve(root1, bst1);
       solve(root2, bst2);
       
       vector<int> mergedArray = mergeArrays(bst1,bst2);
       
       int start = 0;
       int end = mergedArray.size()-1;

       return inBST(mergedArray, start, end);
       
}