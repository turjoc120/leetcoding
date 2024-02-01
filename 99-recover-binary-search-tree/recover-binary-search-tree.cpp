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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* last;

    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->left);
        if(prev && root->val < prev->val){
            if(!first) first = prev;
            last = root;
        }
        prev = root;
        helper(root->right);
    }

    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        helper(root);
        swap(first->val, last->val);
    }

};