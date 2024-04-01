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

// revisit it

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

/////////////////
// >>>>>>>>>>>>floor squre root of a number
int floorSqrt(int n)
{
    int start = 1, end = n;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if (mid * mid <= n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return end;
}

// revisit done
int pow(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

// get nth root
int NthRoot(int n, int m)
{
    int start = 1, end = m;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        long long val = pow(mid, n, m);
        if (val == 1)
            return mid;
        else if (val == 0)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}