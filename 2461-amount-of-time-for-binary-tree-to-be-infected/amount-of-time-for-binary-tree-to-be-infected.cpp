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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*>vis;

    void getParents(TreeNode* root, TreeNode* prev,TreeNode* &targetNode, int target){
        if(root==NULL) return;
        if(root->val==target) targetNode=root;
        parent[root]=prev;
        getParents(root->left, root, targetNode, target);
        getParents(root->right, root, targetNode, target);
    }
    
    void helper(TreeNode* target, int &time, int k){
        if(target==NULL) return;
        if(vis.find(target) != vis.end()) return;
        vis.insert(target);
        time=max(time, k);
        helper(target->left, time, k+1);
        helper(target->right, time, k+1);
        helper(parent[target], time, k+1);
    }

    int amountOfTime(TreeNode* root, int start) {
        int time=0, k=0;
        TreeNode* targetNode;
        getParents(root, NULL, targetNode, start);
        helper(targetNode, time, k);
        return time;
    }
};