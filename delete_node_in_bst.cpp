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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(root->val>key)
            root->left = deleteNode(root->left, key);
        else if(root->val<key)
            root->right = deleteNode(root->right, key);
        
        else{
            
            if(!root->left && !root->right){
                delete root;
                root=NULL;
            }
            
            else if(!root->left){
                TreeNode * temp = root;
                root = root->right;
                delete temp;
            }
            
            else if(!root->right){
                TreeNode *temp = root;
                root = root->left;
                delete temp;
            }
            
            else{
                TreeNode *temp = root->right;
                while(temp->left!=NULL)
                    temp = temp->left;
                
                root->val = temp->val;
                root->right = deleteNode(root->right, root->val);
            }
            
        }
        
        return root;
    }
};