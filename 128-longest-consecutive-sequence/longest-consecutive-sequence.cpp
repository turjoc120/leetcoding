class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i: nums) s.insert(i);
        int ans=0;
        for(auto i:s){
            if(s.find(i-1) == s.end()){
                int curr=i, temp=0;
                while(s.find(curr) != s.end()){
                    curr++; temp++;
                }
                ans=max(ans, temp);
            }
        }
        return ans;
    }
};