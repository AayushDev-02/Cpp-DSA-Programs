void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
        
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex){
        
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        } 
        
        int element = pre[index++];
        
        Node* root = new Node(element);
        
        int position;
        position = nodeToIndex[element];
        
        // left - recursive call
        root->left = solve(in,pre,index, inOrderStart, position-1 , n,nodeToIndex);
        // left - recursive call
        root->right = solve(in , pre , index , position+1 , inOrderEnd , n, nodeToIndex);
        
        return root;
        
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        
        map<int,int> nodeToIndex;
        
        // create nodes to index mapping
        createMapping(in, nodeToIndex, n);
        
        int inOrderStart = 0;
        int inOrderEnd = n-1;
        
        Node* ans = solve(in, pre, preOrderIndex, inOrderStart, inOrderEnd , n, nodeToIndex);
        
        return ans;
    }