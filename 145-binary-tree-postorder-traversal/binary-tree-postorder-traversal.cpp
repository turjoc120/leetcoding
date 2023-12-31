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
        vector<int>ans;
        if(!root) return ans;

        stack<TreeNode*>st;
        st.push(root); root=root->left;
        TreeNode* prev=NULL;

        while(!st.empty()){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                TreeNode* peak = st.top();
                if(peak->right != NULL && prev != peak->right) root= peak->right;
                else{
                    ans.push_back(peak->val);
                    prev=peak;
                    st.pop();
                }
            }
        }

        return ans;
    }
};