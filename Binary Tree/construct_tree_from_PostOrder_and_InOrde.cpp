//Function to return a tree created from postorder and inoreder traversals.

void createMapping(int in[], map<int,int> &nodeToIndex, int n){
    
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
    
}

Node* solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex){
    
    // base case
    if(index < 0 || inOrderStart > inOrderEnd ){
        return NULL;
    }
    
    // create a root node element
    int element = post[index--];
    Node* root = new Node(element);
    
    // find element's index in inorder
    int position = nodeToIndex[element];
    
    // Recursive calls - in case of post order and inorder we first build the right subtree and then build left subtree
    
    // right 
    root->right = solve(in, post, index, position+1, inOrderEnd , n, nodeToIndex);
    // left
    root->left = solve(in, post, index, inOrderStart, position-1, n, nodeToIndex);
   
    return root;
    
}


Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1;
    int inOrderStart = 0;
    int inOrderEnd = n-1;
    
    map<int,int> nodeToIndex;
    // create node to index mapping
    createMapping(in, nodeToIndex, n);
    
    Node* ans = solve(in, post, postOrderIndex, inOrderStart, inOrderEnd, n,  nodeToIndex   );
    
    return ans;
    
}
