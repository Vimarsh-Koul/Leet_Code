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
    
    TreeNode * append(TreeNode *root, int val){
        
        if(root==NULL){
            TreeNode *temp = new TreeNode(val);
            return temp;
        }
        
        if(root->val>val)
            root->left = append(root->left,val);
        else
            root->right = append(root->right, val);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL;
        for(auto it : preorder){
            root = append(root, it);
        }
        return root;
    }
};