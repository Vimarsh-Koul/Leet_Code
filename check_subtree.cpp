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

bool check(TreeNode *s, TreeNode *t){
    if(!s && !t)
        return true;
    
    
    if(s && t && s->val==t->val)
        return check(s->left,t->left) && check(s->right, t->right);
    return false;
}

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        if(s==NULL || t==NULL)
            return false;
        
        if(s->val==t->val && check(s,t))
           return true;
        
            return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};