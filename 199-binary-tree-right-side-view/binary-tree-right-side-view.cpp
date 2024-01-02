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
        map<int,int>mp;
        vector<int> ans;
        helper(root, mp, 0);
        for(auto i: mp) ans.push_back(i.second);
        return ans;
    }

    void helper(TreeNode* root, map<int,int> &mp, int hlvl){
        if(root==NULL) return;
        mp[hlvl]=root->val;
        helper(root->left, mp, hlvl+1);
        helper(root->right,mp, hlvl+1);
    }
};