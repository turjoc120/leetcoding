class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto i: nums) s.insert(i);
        int longest=0;

        for(auto i: s){
            if(s.find(i-1) == s.end()){
                int count=0, iterator=i;
                while(s.find(iterator) != s.end()){
                    iterator++;
                    count++;
                }
                longest=max(longest, count);
            }
        }
        return longest;
    }
};