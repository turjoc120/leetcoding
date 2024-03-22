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
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* prev=NULL;
        
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                TreeNode* peak = st.top(); 
                if(peak->right && peak->right != prev) root = peak->right;
                else{
                    ans.push_back(peak->val);
                    st.pop();
                    prev = peak;
                }
            }
        }
        return ans;
    }
};