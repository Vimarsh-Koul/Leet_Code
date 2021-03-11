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
    int deepestLeavesSum(TreeNode* root) {
     unordered_map<int,int> map;
        
        
        
        queue<TreeNode *> q;
        q.push(root);
        int level =0;
        while(!q.empty()){
            int s = q.size();
            int ans =0;
            for(int i=0;i<s;i++){
                TreeNode * t = q.front();
                q.pop();
                ans+=t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            map[level++]= ans;
        }
        
        return map[level-1];
    }
};