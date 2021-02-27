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
    
    void solve(TreeNode* root, vector<vector<int>> &ans, vector<int> temp, int target, int sum){
        
        if(!root->left && !root->right){
            if(root->val+sum==target){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(root->val);
        if(root->left)
            solve(root->left, ans, temp, target, sum+root->val);
        
        if(root->right)
            solve(root->right, ans, temp, target, sum+root->val);
        return;
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        vector<int> temp;
        
        solve(root, ans, temp, targetSum, 0);
        return ans;
    }
};