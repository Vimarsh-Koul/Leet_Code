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
    struct tree{
            int min;
            int max;
            int sum;
            bool isbst;
        };
    
    tree solve(TreeNode* root, int &maxsum){
        tree curr;
        
        if(!root){
            curr.min = INT_MAX;
            curr.max = INT_MIN;
            curr.sum = 0;
            curr.isbst= true;
            maxsum = max(maxsum,curr.sum);
            return curr;
        }
        
        tree left = solve(root->left, maxsum);
        tree right = solve(root->right, maxsum);
        
        if(left.isbst && right.isbst && root->val> left.max && root->val<right.min){
            curr.sum = root->val + left.sum + right.sum;
            curr.isbst = true;
            curr.max = max(right.max, root->val);
            curr.min = min(left.min, root->val);
            maxsum = max(maxsum, curr.sum);
        }
        else{
            curr.sum = 0;
            curr.min = INT_MAX;
            curr.max = INT_MIN;
            curr.isbst= false;
            maxsum = max(maxsum, curr.sum);
        }
        return curr;
    }
    
    int maxSumBST(TreeNode* root) {
        
        if(!root)
            return 0;
        int maxsum = INT_MIN;
        solve(root, maxsum);
        return maxsum;
    }
};