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
int ans =0;
class Solution {
public:
    
    
    void solve(TreeNode *root, int x){
        if(!root)
            return;
        
        x^=(1<<(root->val));
        
        if(root->left==NULL && root->right==NULL){
         if((x&(x-1))==0)
             ans++;
        }   
        solve(root->left,x);
        solve(root->right,x);
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL)
            return 0;
        
        if(!root->left && !root->right)
            return 1;

        int x=0;
        ans=0;
        solve(root, x);
        return ans;
    }
};