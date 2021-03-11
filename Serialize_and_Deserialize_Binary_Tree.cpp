/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string preorder(TreeNode *root){
        if(!root)
            return "X";
        string leftree = preorder(root->left);
        string righttree = preorder(root->right);
        return to_string(root->val)+','+leftree+','+righttree;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = preorder(root);
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return de(iss);
    }
    
    TreeNode *de(istringstream& iss){
        string token;
        getline(iss,token,',');
        if(token=="X")
            return NULL;
        TreeNode *root = new TreeNode(stoi(token));
        root->left = de(iss);
        root->right = de(iss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));