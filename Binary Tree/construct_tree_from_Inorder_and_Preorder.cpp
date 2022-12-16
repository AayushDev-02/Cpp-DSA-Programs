int findPosition(int in[], int element, int n){
        
        for(int i=0; i<n; i++){
            if(in[i] == element){
                return i;
            }
        }
        
        return -1;
        
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
        
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        } 
        
        int element = pre[index++];
        
        Node* root = new Node(element);
        
        int position;
        position = findPosition(in, element, n);
        
        // left - recursive call
        root->left = solve(in,pre,index, inOrderStart, position-1 , n);
        // left - recursive call
        root->right = solve(in , pre , index , position+1 , inOrderEnd , n);
        
        return root;
        
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        
        int inOrderStart = 0;
        int inOrderEnd = n-1;
        
        Node* ans = solve(in, pre, preOrderIndex, inOrderStart, inOrderEnd , n);
        
        return ans;
    }