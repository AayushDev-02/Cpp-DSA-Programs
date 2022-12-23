void solve(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }
    
    int isPairPresent(struct Node *root, int target)
    {
    
        vector<int> ans;
        solve(root, ans);
        
        int i=0;
        int j = ans.size()-1;
        
        bool final = false;
        
        while(i<j){
            if(ans[i] + ans[j] == target){
                final = true;
                break;
            }
            else if(ans[i] + ans[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        
        if(final){
            return 1;
        }
        
        return 0;
    
    }