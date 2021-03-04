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
    unordered_map<TreeNode *, int> map;
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        if(map.find(root)!=map.end())
            return map[root];
        
        int temp = root->val;
        if(root->left)
            temp+= rob(root->left->left) + rob(root->left->right);
        if(root->right)
            temp+= rob(root->right->left) + rob(root->right->right);
        
        int nr = rob(root->left) + rob(root->right);
        map[root]= max(temp, nr);
        return map[root];
    }
};