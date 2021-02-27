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
    
    bool solve(TreeNode *p, TreeNode* q){
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val==q->val){
            bool c0 = solve(p->left, q->left);
            bool c1 = solve(p->right, q->right);
            return (c0 && c1);
        }
        return false;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        return solve(p,q);
    }
};