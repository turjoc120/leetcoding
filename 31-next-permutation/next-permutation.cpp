class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1, n = nums.size()-1;

        for(int i = n-1; i>=0; i--){
            if(nums[i]< nums[i+1]){
                idx=i;
                break;
            }
        }

        if(idx==-1){
            reverse(nums.begin(), nums.end());
        }else{
            for(int i = n; i>=idx; i--){
                if(nums[i] > nums[idx]){
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
            reverse(nums.begin()+idx+1, nums.end());
        }
    }
};