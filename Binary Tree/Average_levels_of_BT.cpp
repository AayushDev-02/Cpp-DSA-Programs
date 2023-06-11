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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;

        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        double avg = 0;
        int i=0;
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode!= NULL){
                int x = frontNode->val;
                i++;
                avg+=x;

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }

                
            }else{
                avg = avg/i;
                ans.push_back(avg);
                avg = 0; i=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }   
            
        }

        return ans;
    }
};