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
    TreeNode* prev = NULL;
    void preorder(TreeNode* root){
        if(root==NULL) return;
        if(prev){
            prev->right = root;
            prev->left = NULL;
        }
        TreeNode* rightNode=root->right;
        prev = root;
        preorder(root->left);
        preorder(rightNode);
    }

    void flatten(TreeNode* root) {
        if(root==NULL) return;
        preorder(root);
    }
};