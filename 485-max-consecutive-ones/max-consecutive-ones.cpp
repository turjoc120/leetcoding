class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0, count=0;
        for(auto i: nums){
            if(i==0) {
                ans= max(ans, count);
                count=0;
            }
            else count++; 
        }
        ans=max(ans,count);
        return ans;
    }
};