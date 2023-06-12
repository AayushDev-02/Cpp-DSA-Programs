


Node* sortedLLToBST(Node* &head, int n){
    if( n<=0 || head == NULL) return NULL;


    //solve left subtree
    Node* left = sortedLLToBST(head, n-1-n/2);

    Node* root = head;

    root-> left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n/2);

    return root;

}