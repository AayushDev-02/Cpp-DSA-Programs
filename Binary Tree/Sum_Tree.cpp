// O(N^2) complexity approach -----------------------------------------------------------------
int values(Node* root){
        
        if(root == NULL){
            return 0;
        }
        
        int left = values(root->left);
        int right = values(root->right);
        
        int curr = root->data;
        
        int ans = left+right+curr;
        return ans;
        
    }
    
    
    bool isSumTree1(Node* root)
    {
        if(root == NULL){
            return true;
        }
         
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        bool left = isSumTree(root->left);
        bool right = isSumTree(root->right);
        
        int leftValue = values(root->left);
        int rightValue = values(root->right);
        
        int currValue = root->data;
        
        bool cnd3 = (leftValue + rightValue) == currValue;
        
        if(left && right && cnd3){
            return true;
        }
        else{
            return false;
        }
         
         
    }
// O(N^2) complexity approach -----------------------------------------------------------------



// O(N) complexity approach -------------------------------------------------------------------

pair<bool , int> isSumTreeFast(Node* root){
        
        if(root==NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool,int>p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);
        
        bool cnd1 = left.first;
        bool cnd2 = right.first;
        
        int leftValue = left.second;
        int rightValue = right.second;
        int currValue = root->data;
        
        bool cnd3 = (leftValue+rightValue) == currValue;
        
        pair<bool , int> ans;
        ans.second = leftValue + rightValue + currValue;
        
        if(cnd1 && cnd2 && cnd3){
            ans.first = true;
        }else{
            ans.first = false;
        }
        
        return ans;
    } 
    
// O(N) complexity approach -------------------------------------------------------------------
    
    bool isSumTree2(Node* root)
    {
        
        return isSumTreeFast(root).first;
         
    }



























// O(N) complexity approach -------------------------------------------------------------------