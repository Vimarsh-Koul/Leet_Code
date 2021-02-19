/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* anc(TreeNode *root, TreeNode* p, TreeNode* q){
    if(root==NULL)
        return NULL;
    if(root==p || root==q)
        return root;
    TreeNode* left = anc(root->left, p,q);
    TreeNode *right = anc(root->right, p,q);
    
    if(left==NULL && right==NULL)
        return NULL;
    if(left!=NULL && right!=NULL)
        return root;
    
    return (left==NULL)?right:left;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return anc(root,p,q);
    }
};