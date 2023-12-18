class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missing = 0;
        for(auto i: nums) missing=missing^i;
        return missing;
    }
};