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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(stringstream &s){
        string str;
        getline(s, str, ',');
        if(str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = helper(s);    
        root->right = helper(s);
        return root;    
    }

    TreeNode* deserialize(string data) {
        stringstream s(data);
        return helper(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));