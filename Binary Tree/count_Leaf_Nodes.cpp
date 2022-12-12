/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void inorder(BinaryTreeNode<int>* root, int &count){

    //base case
    if(root == NULL){
        return;
    }

    // L
    inorder(root->left, count);
    // N
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    // R
    inorder(root->right, count);

}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt = 0;
    
    inorder(root, cnt);
    
    return cnt;
    
}