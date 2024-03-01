/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        Node* curr = root;
        while(curr->left){
            Node* nxt = curr;
            while(nxt){
                nxt->left->next = nxt->right;
                if(nxt->next) nxt->right->next = nxt->next->left;
                nxt = nxt->next;
            }
            curr = curr->left;
        }
        return root;
    }
};