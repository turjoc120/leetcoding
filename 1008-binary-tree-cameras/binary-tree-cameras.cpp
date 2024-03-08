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
        if(!root) return 1;

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        if(left == 0 || right == 0){
            ans++;
            return 2;
        }
        else if(left == 2 || right == 2) return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if(helper(root, ans) == 0) ans++;
        return ans;
    }
};