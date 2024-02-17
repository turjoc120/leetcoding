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
    int helper(TreeNode* root, int &ans){
        if(root == NULL) return 1;
        int left = helper(root->left,ans);
        int right = helper(root->right,ans);
        if(left == -1 || right == -1){
            ans++;
            return 0;
        }
        if(left == 0 || right == 0) return 1;
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if(helper(root, ans) == -1) ans++;
        return ans;
    }
};