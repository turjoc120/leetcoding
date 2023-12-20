class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority, count=0;
        for(auto i: nums){
            if(!count){
                majority=i;
                count=1;
            }else{
                i == majority? count++: count--;
            }
        }

        return majority;
    }
};