class Solution {
  public:
  
  
    int countNode(struct Node* root){
        if(root == NULL){
            return 0;
        }
        
        int ans = 1 + countNode(root->left) + countNode(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* root, int index, int nodeCount){
        if(root == NULL){
            return true;
        }
        
        if( index >= nodeCount ){
            return false;
        }
        else {
            bool left = isCBT(root->left, index*2+1, nodeCount);
            bool right = isCBT(root->right, index*2+2, nodeCount);
            
            return (left && right);
        }
    }
    
    bool isMaxOrder(struct Node* root){
        
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        else if(root->right == NULL){
            if(root->data > root->left->data){
                return true;
            }
            return false;
        }
        else{
            bool left = root->data > root->left->data;
            bool right = root->data > root->right->data;
            bool cnd3 = isMaxOrder(root->left);
            bool cnd4 = isMaxOrder(root->right);
            
            return (left && right && cnd3 && cnd4);
        }
        
        // return  false;
    }
    
  
    bool isHeap(struct Node* tree) {
        
        int index=0;
        
        int nodeCount = countNode(tree);
        
        if(isCBT(tree, index, nodeCount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
        
    }
};