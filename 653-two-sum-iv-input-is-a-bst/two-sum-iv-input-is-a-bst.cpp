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
class BsIt {
    stack<TreeNode*> st;
    bool isReverse;
public:
    BsIt(TreeNode* root, bool reverse){
        if(reverse) isReverse = true;
        pushAll(root);
    }

    int next(){
        TreeNode* temp = st.top(); st.pop();
        pushAll(isReverse ? temp->left : temp->right);
        return temp->val;
    }

private:
    void pushAll(TreeNode* root){
        if(root==NULL) return;
        st.push(root);
        pushAll(isReverse ? root->right : root->left);
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BsIt l(root, false);
        BsIt r(root, true);
        
        int i = l.next(), j = r.next();


        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};