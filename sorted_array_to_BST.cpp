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

TreeNode* formtree(vector<int> &nums, int l, int r){
    if(l>r)
        return NULL;
    int mid = l + (r-l)/2;
    TreeNode *temp = new TreeNode(nums[mid]);
    temp->left = formtree(nums, l, mid-1);
    temp->right = formtree(nums, mid+1, r);
    return temp;
}



class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        
        return formtree(nums, 0,nums.size()-1);
    }
};