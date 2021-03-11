/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    void solve(TreeNode *org, TreeNode *clo, TreeNode *target, TreeNode **ans){
        if(!org)
            return;
        
        if(org==target){
            *ans = clo;
            return;
        }
            
        
        solve(org->left, clo->left, target, ans);
        solve(org->right,clo->right, target, ans);
        return;
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *ans;
        solve(original, cloned,target, &ans);
        return ans;
    }
};