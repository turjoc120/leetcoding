class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0, n= nums.size();

        for(int i =0; i<n; i++){
            if(nums[(i+1) % n] < nums[i]) flag++;
            if(flag > 1) return false; 
        }
        return true;
    }
};