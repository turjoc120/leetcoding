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
    TreeNode* helper(vector<int>& pre,unordered_map<int,int> &mp, int ps, int pe,int is, int ie){
        if(ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        int inRoot = mp[pre[ps]];
        int leftItem = inRoot-is;
        root->left = helper(pre, mp, ps+1, pe, is, inRoot-1);
        root->right = helper(pre, mp, ps+leftItem+1, pe, inRoot+1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;
        return helper(preorder, mp, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};