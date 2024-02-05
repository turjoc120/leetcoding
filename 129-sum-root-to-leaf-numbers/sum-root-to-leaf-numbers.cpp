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
    int helper(TreeNode* root, int sum){
        if(!root) return 0;
        if(!root->left && !root->right) return sum*10+root->val;
        int l = helper(root->left, sum*10+root->val);
        int r = helper(root->right, sum*10+root->val);
        return l+r;
    }

    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};