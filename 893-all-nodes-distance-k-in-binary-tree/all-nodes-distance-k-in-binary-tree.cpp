/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> vis;

    void getParents(TreeNode* root, TreeNode* prev){
        if(root==NULL) return;
        parent[root]= prev;
        getParents(root->left, root);    
        getParents(root->right, root);    
    }

    void helper(TreeNode*target, int k, vector<int> &ans){
        if(target == NULL || vis.find(target) != vis.end()) return;
        vis.insert(target);
        if(k == 0){
            ans.push_back(target->val);
            return;
        }
        helper(target->left, k-1, ans);
        helper(target->right, k-1, ans);
        helper(parent[target], k-1, ans);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        getParents(root, NULL);
        helper(target, k, ans);
        return ans;
    }
};