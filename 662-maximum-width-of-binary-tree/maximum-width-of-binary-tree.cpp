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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;

        while(!q.empty()){
            int n=q.size(), start, end;
            for(int i=0; i<n; i++){
                long long idx=q.front().second;
                TreeNode* node = q.front().first;
                if(i==0) start=q.front().second;
                if(i==n-1) end=q.front().second;
                q.pop();
                if(node->left) q.push({node->left, idx*2+1});
                if(node->right) q.push({node->right, 2*idx+2});
            }
            ans= max(ans, end-start+1);
        }
        return ans;
    }
};