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
    
    bool solve(TreeNode * l, TreeNode * r){
        if(!l && !r)
            return true;
        if(!l || !r)
            return false;
        
        if(l->val==r->val){
            bool c0 = solve(l->left, r->right);
            bool c1 = solve(l->right, r->left);
            return c0 && c1;
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return false;
        return solve(root->left, root->right);
    }
};