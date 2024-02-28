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
    TreeNode* helper(vector<int>& pre,unordered_map<int, int> &mp, int &preS, int preE, int poS, int poE){
        if(preS > preE || poS > poE) return NULL;
        TreeNode* root = new TreeNode(pre[preS++]);
        if(poS >= poE ) return root;
        int idx = mp[pre[preS]];
        root->left = helper(pre, mp, preS, preE, poS, idx);
        root->right = helper(pre, mp, preS, preE, idx + 1, poE-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int>mp;
        for(int i = 0; i < postorder.size(); i++) mp[postorder[i]] = i;
        int preS = 0;
        return helper(preorder, mp, preS, preorder.size()-1, 0, postorder.size()-1);
    }
};