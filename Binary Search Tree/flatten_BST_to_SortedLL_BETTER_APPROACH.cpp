
void solve(TreeNode<int>* root, TreeNode<int>* &head){
    if(root == NULL) return;

    //right part
    solve(root->right, head);

    //connect the head of right subtree to the right of the root
    root->right = head;

    // if head is not null make the prev connection of head to root;
    if(head != NULL ){
        head->left = root;
    }
    
    head = root;

    //left part
    solve(root->left, head);

    
}


TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{

    TreeNode<int>* head = NULL;
    solve(root, head);

    return head;
}