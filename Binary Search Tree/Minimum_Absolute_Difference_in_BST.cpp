/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int &p, int &m){
        //lnr

        if(root->left != NULL){
            solve(root->left, p, m);
        }

        if(p >= 0){
            m = min(m, root->val - p);
        }

        p = root->val;

        if(root->right != NULL){
            solve(root->right , p, m);
        }


    }

    int getMinimumDifference(TreeNode* root) {
        
        int mini = INT_MAX;
        int parentVal = -1;
        solve(root,parentVal, mini );
        return mini;
        
    }
};