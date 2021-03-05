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
    
    void solve(TreeNode *root, int &sum, int &paths, vector<int> &s){
        if(root==NULL)
            return;
        s.push_back(root->val);
        solve(root->left, sum, paths, s);
        solve(root->right, sum, paths, s);
        int temp=0;
        for(int i=s.size()-1;i>=0;i--){
            temp+=s[i];
            if(temp==sum)
                paths++;
        }
        s.pop_back();
        return;
    }
    
    int pathSum(TreeNode* root, int sum) {
        int paths=0;
        vector<int> s;
        solve(root, sum, paths, s);
        return paths;
    }
};