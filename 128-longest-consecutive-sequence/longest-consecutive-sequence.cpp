class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i: nums) s.insert(i);
        int ans=0;
        for(int i=0; i< nums.size(); i++){
            if(s.find(nums[i]-1) == s.end()){
                int curr=nums[i],temp=0;
                while(s.find(curr) != s.end()){
                    curr++; temp++;
                }
                ans=max(ans, temp);
            }
        }
        return ans;
    }
};