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
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_set<TreeNode *> vis;

    void getParents(TreeNode *root, TreeNode *prev, TreeNode *&targetNode, int target)
    {
        if (root == NULL)
            return;
        if (root->val == target)
            targetNode = root;
        parent[root] = prev;
        getParents(root->left, root, targetNode, target);
        getParents(root->right, root, targetNode, target);
    }

    void helper(TreeNode *target, int &time, int k)
    {
        if (target == NULL)
            return;
        if (vis.find(target) != vis.end())
            return;
        vis.insert(target);
        time = max(time, k);
        helper(target->left, time, k + 1);
        helper(target->right, time, k + 1);
        helper(parent[target], time, k + 1);
    }

    int amountOfTime(TreeNode *root, int start)
    {
        int time = 0, k = 0;
        TreeNode *targetNode;
        getParents(root, NULL, targetNode, start);
        helper(targetNode, time, k);
        return time;
    }
};

class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mid = n / 2;
        long long ops = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > k && i <= mid)
                ops += (nums[i] - k);
            else if (nums[i] < k && i >= mid)
                ops += (k - nums[i]);
        }
        return ops;
    }
};

// monotonic subarray
int longestMonotonicSubarray(vector<int> &nums)
{
    int inC = 1, deC = 1, ans1 = 0, ans2 = 0, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && nums[i] < nums[i + 1])
            inC++;
        else
        {
            ans1 = max(ans1, inC);
            inC = 1;
        }
        if (i + 1 < n && nums[i] > nums[i + 1])
            deC++;
        else
        {
            ans2 = max(deC, ans2);
            deC = 1;
        }
    }
    return ans1 > ans2 ? ans1 : ans2;
}