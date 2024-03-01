//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}
// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* helper(vector<int> arr){
    if(arr.size() == 0) return NULL;
    Node* root = new Node(arr[0]);
    vector<int> left;vector<int> right;
    for(int i=1; i<arr.size(); i++){
        if(arr[i] < root->data) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    root->left = helper(left);
    root->right = helper(right);
    return root;
    
}

Node* constructBst(int arr[], int n)
{
    vector<int> v;
    for(int i = 0; i < n; i++) v.push_back(arr[i]);
    return helper(v);
}
