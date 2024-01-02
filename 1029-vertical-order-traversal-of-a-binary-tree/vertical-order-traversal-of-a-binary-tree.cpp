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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>ds;
        preorder(root,0,0,ds);

        vector<vector<int>> ans;
        for(auto i: ds){
            vector<int>temp;
            for(auto j: i.second)  temp.insert(temp.end(), j.second.begin(), j.second.end());
            ans.push_back(temp);
        }
        return ans;
    }

    void preorder(TreeNode* root, int vlvl, int hlvl, map<int, map<int, multiset<int>>> &ds){
        if(root==NULL) return;
        ds[vlvl][hlvl].insert(root->val);
        preorder(root->left, vlvl-1, hlvl+1, ds);
        preorder(root->right, vlvl+1, hlvl+1, ds);
    }
};