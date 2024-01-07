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

    TreeNode* helper(unordered_map<int,int>&mp,vector<int>pre, long long &idx, int is, int ie){
        if( is > ie) return NULL;
        int item=pre[idx++];
        TreeNode* root = new TreeNode(item);
        int inRoot = mp[item];
        root->left = helper(mp, pre, idx, is, inRoot-1);
        root->right = helper(mp, pre, idx, inRoot+1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;
        long long idx=0;
        return helper(mp,preorder,idx, 0, inorder.size()-1);
    }
};