//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
unordered_map<int,int>umap;
Node*solve(int level,int in[],int levelorder[],int s,int e,int n){
   if(level>n-1)return NULL;
   int indx=umap[levelorder[level]];
   Node*root=new Node(levelorder[level]);
   root->left=solve(2*level+1,in,levelorder,s,indx-1,n);
   root->right=solve(2*level+2,in,levelorder,indx+1,e,n);
   return root;
   
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
for(int i=0;i<n;i++){
   umap[inorder[i]]=i;
}
Node*root=solve(0,inorder,levelOrder,iStart,iEnd,n);
return root;
}