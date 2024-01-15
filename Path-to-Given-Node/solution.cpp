/*

Path to Given Node
Programming
Tree Data Structure
Easy
66.7% Success

579

19

Bookmark
Asked In:
Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
 1 <= N <= 105

 1 <= Data Values of Each Node <= N

 1 <= B <= N



Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7


B = 5

Input 2:

 A =
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [1]


Example Explanation
Explanation 1:

 We need to find the path from root node to node with data value 5.
 So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]
Explanation 2:

 We need to find the path from root node to node with data value 1.
 As node with data value 1 is the root so there is only one node in the path.
 So we will return [1]

*/

bool helper(TreeNode *root, int target, vector<int> &ans)
{
    // if its null we havent found the target yet so need to remove so return false;
    if (root == NULL)
        return false;
    ans.push_back(root->val);
    // found no need to call furter time to go back without removing
    if (root->val == target)
        return true;
    // if any of the branches have target just return no need to go further
    if (helper(root->left, target, ans) || helper(root->right, target, ans))
        return true;
    // otherwise we need to remove and rturn flase not found yet
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> ans;
    helper(A, B, ans);
    return ans;
}