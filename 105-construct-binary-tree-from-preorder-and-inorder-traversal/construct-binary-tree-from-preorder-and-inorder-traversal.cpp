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
    TreeNode* helper(vector<int>& pre,unordered_map<int,int>&mp, int &i, int pe, int is, int ie){
        if(i > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(pre[i]);
        int inRoot = mp[pre[i++]];
        root->left = helper(pre, mp, i, pe, is, inRoot-1);
        root->right = helper(pre, mp, i, pe, inRoot+1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int i = 0;
        return helper(preorder,mp,i,preorder.size()-1, 0, inorder.size()-1);
    }
};