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
    
    void sorder(TreeNode *root,vector<int> &temp){
        if(root==NULL)
            return;
        sorder(root->right, temp);
        temp.push_back(root->val);
        sorder(root->left, temp);
        return;
    }
    
    void solve(TreeNode *root, vector<int> &temp, int *index){
        if(root==NULL)
            return;
        solve(root->right, temp,index);
        root->val = temp[(*index)++];
        solve(root->left, temp,index);
        return;
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> temp;
        sorder(root, temp);
        for(auto it: temp)
            cout<<it<<" ";
        cout<<endl;
        
        for(int i=1;i<temp.size();i++){
            temp[i]+=temp[i-1];
        }
        for(auto it: temp)
            cout<<it<<" ";
        cout<<endl;
        int index =0;
        solve(root, temp,&index);
        
        return root;
    }
};