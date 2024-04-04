class Solution {
public:
    int feasible(vector<int>& nums, int mid){
        int sum = 0;
        for(auto i: nums){
            sum += ceil((double)i / (double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start =1, end;
        for(auto i: nums) end = max(end, i);

        while(start <= end){
            int mid = (start + end) / 2;
            if(feasible(nums, mid) <= threshold) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};