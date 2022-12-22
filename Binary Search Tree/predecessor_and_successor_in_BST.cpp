pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int succ = -1;
    while(temp->data != key){
        
        if(temp->data > key){
//             succ = temp->data;
            temp = temp->left;
        }
        else{
//             pred = temp->data;
            temp = temp->right;
        }   
    }
    
//     predecessor
    BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree!=NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
//     successor
    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree!=NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    pair<int,int> ans = make_pair(pred, succ);
    
    return ans;
    
    
}



//----------------------------------------------------- GFG SOLUTION
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    pre=NULL;
    suc=NULL;

    Node * temp = root;

    while(temp!= NULL){

        if(temp->key>key){
            suc= temp ;
            temp=temp->left;
        }
        else{
            temp= temp->right ;
        }
    }

    Node * tip= root;

    while(tip!= NULL){
        if(tip->key<key){
            pre= tip ;
            tip=tip->right;
        }
        else{
            tip= tip->left ;
        }
    }

} 

