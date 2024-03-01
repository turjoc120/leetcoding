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
    void helper(TreeNode* root, int curr, int &ans){
        if(root == NULL) return;
        if(!root->left && !root->right) ans+= (curr*10 + root->val);
        helper(root->left, curr*10+root->val, ans);
        helper(root->right, curr*10+root->val, ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};