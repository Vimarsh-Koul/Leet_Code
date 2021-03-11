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
    
    void solve(TreeNode *root, int &ans){
        if(root==NULL)
            return;
        if(root->val%2==0){
            cout<<root->val<<endl;
            if(root->left && root->left->left)
                ans+=root->left->left->val;
            
            if(root->left && root->left && root->left->right)
                ans+=root->left->right->val;
            
            if(root->right && root->right->left)
                ans+=root->right->left->val;
            
            if(root->right && root->right->right)
                ans+=root->right->right->val;
        }
        
        solve(root->left,ans);
        solve(root->right,ans);
        return;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int ans =0;
        solve(root,ans);
        return ans;
    }
};