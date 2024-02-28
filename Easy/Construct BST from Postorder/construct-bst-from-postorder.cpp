//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* helper(int post[], int &n, long minVal, long maxVal){
    if(n < 0 || post[n] >= maxVal || post[n] <= minVal)
        return NULL;
    Node* root = new Node(post[n--]);
    root->right = helper(post, n, root->data, maxVal);
    root->left = helper(post, n, minVal, root->data);
    return root;
}

Node *constructTree (int post[], int size)
{
    int n = size-1;
    return helper(post, n, LONG_MIN, LONG_MAX);
}