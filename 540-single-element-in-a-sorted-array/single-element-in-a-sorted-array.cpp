class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int start = 0, last = nums.size()-1;
        while(start <= last){
            int mid = start + (last - start) / 2;
            if(mid % 2 == 0 && (mid + 1 < n && nums[mid] == nums[mid+1]) ||
            mid % 2 == 1 && (mid - 1 >= 0 && nums[mid] == nums[mid-1]))
                start = mid + 1;
            else last = mid - 1;
        }
        return nums[start];
    }
};