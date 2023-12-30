class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
    }

    int mergesort(vector<int> & nums, int start, int end){
        int count=0;
        if(start>=end) return count;
        int mid=(start+end)/2;
        count+=mergesort(nums,start, mid);
        count+=mergesort(nums,mid+1, end);
        count+=merge(nums, start, mid, end);
        return count;
    }

    int merge(vector<int> & nums, int start, int mid, int end){
        int left=start, right=mid+1, count=0;

        while(left <= mid && right <= end){
            if((long) nums[left] > (long) 2*nums[right] ){
                count+=mid-left+1;
                right++;
            }else left++;
        }
        sort(nums.begin()+start, nums.begin()+end+1);
        return count;
    }
};