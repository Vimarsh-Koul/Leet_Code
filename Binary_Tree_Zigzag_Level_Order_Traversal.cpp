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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        vector<int> temp;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode *t = q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                temp.push_back(t->val);
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        for(int i=1;i<ans.size(); i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};