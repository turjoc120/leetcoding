class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start=INT_MIN, end=INT_MIN;

        for(auto i: intervals){
            if(i[0] > end){
                start=i[0];
                end=i[1];
                ans.push_back({start,end});
            }else{
                end=max(end, i[1]);
                ans.back()[1]=end;
            }
        }
        return ans;
    }
};