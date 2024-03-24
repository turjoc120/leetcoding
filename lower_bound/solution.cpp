int lowerBound(vector<int> arr, int n, int x)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}
///////////dummy todo

bool search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[start] == nums[mid] && nums[mid] == nums[end])
            start++, end--;

        else if (nums[start] <= nums[mid])
        {
            if (nums[start] <= target && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return false;
}