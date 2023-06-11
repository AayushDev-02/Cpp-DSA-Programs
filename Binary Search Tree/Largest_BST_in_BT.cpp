//new approach
class NodeValue{
     public:
    
        int maxNode; int minNode; int maxSize;
        
        NodeValue(int min,int max,int size){
            this->maxNode = max;
            this->minNode = min;
            this->maxSize = size;
        }
};


class Solution{
    public: 
    NodeValue solve(Node* root){
        if(root == NULL){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        //check if valid bst
        if((root->data > left.maxNode) && (root->data < right.minNode)){
            // valid bst
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
            
        }
        
        //else not a bst
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return solve(root).maxSize;
    }
};