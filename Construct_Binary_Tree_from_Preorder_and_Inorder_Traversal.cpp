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
    int index = 0;
    
    TreeNode* solve(int ins, int ine, vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &map){
        
        if(ins>ine)
            return NULL;
        TreeNode *root = new TreeNode(preorder[index++]);
        if(ins==ine)
            return root;
        root->left = solve(ins, map[root->val]-1, preorder, inorder, map);
        root->right = solve(map[root->val]+1, ine, preorder, inorder, map);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++)
            map[inorder[i]]=i;
        
        return solve(0,inorder.size()-1, preorder, inorder, map);
    }
};