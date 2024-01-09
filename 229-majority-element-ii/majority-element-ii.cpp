class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1, majority2, count1=0, count2=0;

        for(auto i: nums){
            if(count1 == 0 && i != majority2){
                majority1=i;
                count1=1;
            }
            else if(count2 == 0 && i != majority1){
                majority2=i;
                count2=1;
            }
            else if(i == majority1) count1++;
            else if(i == majority2) count2++;
            else{
                count1--, count2--;
            }
        }

        count1=0, count2=0;
        for(auto i: nums){
            if(i==majority1) count1++;
            else if(i==majority2) count2++;
        }

        vector<int>ans;
        if(count1 > (nums.size()/3)) ans.push_back(majority1);
        if(count2 > (nums.size()/3)) ans.push_back(majority2);
        return ans;
        
    }
};