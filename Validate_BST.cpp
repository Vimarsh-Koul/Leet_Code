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

bool issmall(TreeNode* ele, int val){
    if(ele==NULL)
        return true;
    if(ele->val<val && issmall(ele->left,  val) && issmall(ele->right, val))
        return true;
    return false;
}


bool islarge(TreeNode* ele, int val){
    if(ele==NULL)
        return true;
    if(ele->val>val && islarge(ele->left, val) && islarge(ele->right, val))
        return true;
    return false;
}


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        
        if(issmall(root->left,root->val) && islarge(root->right,root->val) && isValidBST(root->left) && isValidBST(root->right))
            return true;
        else
            return false;
    }
};



// ################################################## //





