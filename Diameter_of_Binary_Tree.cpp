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
    
    int high(TreeNode *root){
        if(root==NULL)
            return -1;
        int t0 = high(root->left);
        int t1 = high(root->right);
        return max(t0,t1)+1;
    }
    
    void solve(TreeNode *root, int &m){
        if(root==NULL)
            return;
        // int h0 = high(root)+2;
        // cout<<h0<<endl;
        int l = high(root->left);
        int r = high(root->right);
        
        m = max(l+r+2,m);
        solve(root->left,m);
        solve(root->right,m);
        return;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
//         int l = solve(root->left);
//         int r = solve(root->right);
//         cout<<l<<" "<<r<<endl;
        
//         return l+r+2;
        int m = INT_MIN;
        solve(root,m);
        return m;
    }
};


// #########################################################

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans =INT_MIN;
        dfs(root,ans);
        return ans;
    }
    
    int  dfs(TreeNode *root, int &ans){
        if(!root)
            return 0;
        int l = dfs(root->left,ans);
        int r = dfs(root->right,ans);
        ans = max(ans, l+r);
        return (max(l,r) +1); 
    }
};
