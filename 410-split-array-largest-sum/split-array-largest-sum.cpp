class Solution {
public:
    bool feasible(vector<int> &nums, int mid, int k){
        int pages = 0;
        for(auto i: nums){
            if(pages + i <= mid) pages+=i;
            else{
                k--;
                pages = i;
            }
        }

         k--;
        if(k < 0) return false;
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int start = -1, end = 0;
        for(auto i: nums){
            start = max(start, i);
            end += i;
        }

        while(start <= end){
            int mid = start + (end - start) /2;
            if(feasible(nums, mid, k)) end = mid - 1;
            else start = mid + 1;
        } 

        return start;
    }
};