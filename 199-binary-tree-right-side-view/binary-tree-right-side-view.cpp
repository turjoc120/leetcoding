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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans,0);
        return ans;
    }

    void helper(TreeNode* root, vector<int> &ans, int lvl){
        if(root==NULL) return;
        if(ans.size()==lvl)ans.push_back(root->val);
        helper(root->right,ans,lvl+1);
        helper(root->left,ans,lvl+1);
    }
};