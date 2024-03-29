class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1, n = nums.size();

        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx=i; break;
            }
        }

        if(idx==-1) reverse(nums.begin(), nums.end());
        else{
            for(int i=n-1; i>=0; i--){
                if(nums[idx] < nums[i]){
                    swap(nums[i],nums[idx]); break;
                }
            }
            reverse(nums.begin()+idx+1, nums.end());
        }
        
    }
};