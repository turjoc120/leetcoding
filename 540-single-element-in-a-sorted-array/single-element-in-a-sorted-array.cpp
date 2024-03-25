class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xor1=0;
        for(auto i: nums) xor1 = xor1^i;
        return xor1;
    }
};