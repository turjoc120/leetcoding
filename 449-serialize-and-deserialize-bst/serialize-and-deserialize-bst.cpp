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
        if(root==NULL) return "";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(queue<int> &q, long ub){
        if(q.empty() || q.front() > ub) return NULL;
        int item = q.front(); 
        q.pop();
        TreeNode* root = new TreeNode(item);
        root->left = helper(q, item);
        root->right = helper(q, ub);
        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str;
        queue<int>q;
        while (getline(s, str, ',')) q.push(stoi(str));
        return helper(q, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;