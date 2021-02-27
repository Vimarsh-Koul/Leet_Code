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
    
    int solve(TreeNode* root, int deep){
        if(root==NULL)
            return deep;
        
        int d0 = solve(root->left, deep);
        int d1 = solve(root->right, deep);
        return max(d0,d1)+ 1;
    }
    
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        return solve(root, 0);
    }
};