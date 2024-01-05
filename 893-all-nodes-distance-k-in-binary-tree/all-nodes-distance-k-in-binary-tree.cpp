/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> vis;

    void getParent(TreeNode* root, TreeNode* prev){
        if(root == NULL) return;
        parent[root]=prev;
        getParent(root->left, root);
        getParent(root->right, root);
    }

    void helper(TreeNode* target, vector<int> &ans, int k){
        if(target==NULL) return;
        if(vis.find(target) != vis.end()) return;
        vis.insert(target);
        if(k==0) ans.push_back(target->val);
        helper(target->left, ans, k-1);
        helper(target->right, ans, k-1);
        helper(parent[target], ans, k-1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        getParent(root, NULL);
        helper(target, ans, k);
        return ans;
    }
};