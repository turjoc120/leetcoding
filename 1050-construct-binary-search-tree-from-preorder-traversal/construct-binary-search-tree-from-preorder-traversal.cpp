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
    TreeNode* helper(vector<int> &pre, long minVal, long maxVal, int &i){
        if(i > pre.size()-1) return NULL;
        if(pre[i] >= maxVal || pre[i] <= minVal) return NULL;
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = helper(pre, minVal, root->val, i);
        root->right = helper(pre, root->val, maxVal, i);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder, LONG_MIN, LONG_MAX, i);
    }
};