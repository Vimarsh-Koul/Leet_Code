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

bool isBal;

int height(TreeNode* root){
    if(root==NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    
    int diff = abs(lh-rh);
    if(diff>1)
        isBal = false;
    
    int h = max(lh, rh) + 1;
    return h;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        isBal= true;
        int h = height(root);
        return isBal;
    }
};