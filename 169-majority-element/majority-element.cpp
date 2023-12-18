class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, majority = -1;

        for(int i=0; i < nums.size(); i++){
            if(count == 0) majority= nums[i];
            if(nums[i] == majority) count++;
            else count--;
        }
        
        return majority;
    }
};