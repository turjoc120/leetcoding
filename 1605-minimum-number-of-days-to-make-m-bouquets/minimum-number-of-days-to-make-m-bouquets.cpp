class Solution {
public:
    bool feasible(vector<int>& bloomDay, int k, int m, int mid){
        int days = 0, adjecent=0;
        for(auto i: bloomDay){
            if(i <= mid) adjecent++;
            else{
                days+= adjecent / k;
                adjecent = 0;
            }
        }
        days+= adjecent / k;
        return days >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long initDays = (long long)m * (long long)k, n = bloomDay.size();
        if(initDays > n) return -1;
        int start = INT_MAX, end= -1;

        for(auto i: bloomDay){
            start = min(i, start);
            end = max(i, end);
        }

        while(start <= end){
            int mid = (start + end) / 2;
            if(feasible(bloomDay, k, m, mid)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};