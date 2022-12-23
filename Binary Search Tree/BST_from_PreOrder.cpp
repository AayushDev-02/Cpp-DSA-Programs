Node* solve(int pre[], int min, int max, int &i, int size){
        if(i>=size){
            return NULL;
        }   
        
        if(pre[i] < min || pre[i] > max){
            return NULL;
        }
        
        Node* root = newNode(pre[i++]);
        root->left = solve(pre, min, root->data, i, size);
        root->right = solve(pre, root->data, max, i, size);
        
        return root;
    }

    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        int min = INT_MIN;
        int max = INT_MAX;
        int i=0;
        return solve(pre, min, max, i, size);
    }