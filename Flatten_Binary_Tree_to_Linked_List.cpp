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
    
    void solve(TreeNode *root, vector<int> &ans){
        if(!root)
            return;
        ans.push_back(root->val);
        solve(root->left, ans);
        solve(root->right, ans);
        return;
    }
    
    void flatten(TreeNode* root) {
        if(!root)
            return;
        vector<int> ans;
        solve(root, ans);
        
        root->left = NULL;
        root->right=NULL;
        TreeNode *temp = root;
        for(int i=1;i<ans.size();i++){
            TreeNode *t = new TreeNode(ans[i]);
            temp->right= t;
            temp=temp->right;
        }
    }
};

// ###########################################################

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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        while(root){
            if(root->left){
            TreeNode *temp = root->left;
            while(temp->right)
                temp=temp->right;
            
            temp->right = root->right;
            root->right = root->left;
            root->left =NULL;
            }
                
            
            root=root->right;
        }
    }
};





