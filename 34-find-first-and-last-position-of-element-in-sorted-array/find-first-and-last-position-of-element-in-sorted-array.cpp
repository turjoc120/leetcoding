class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        vector<int> ans;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target) end = mid-1;
            else start = mid + 1;
        }

        if(start>nums.size()-1||nums.size()==0||nums[start] != target) return {-1,-1};
        ans.push_back(start);
        start=0,end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > target) end = mid-1;
            else start = mid + 1;
        }
        ans.push_back(end);
        return ans;
    }
};