class Solution {
public:
    bool feasible(vector<int> bloomDay, int mid, int m, int k){
        int bouque = 0, flowers=0;
        for(auto i: bloomDay){
            if(i <= mid) flowers++;
            else flowers = 0;
            if(flowers == k) {
                flowers = 0;
                bouque++;
            }
            if(bouque == m) break;
        }
        return bouque == m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
       long long initDays = (long long)m * (long long)k, n = bloomDay.size();
        if(initDays > n) return -1;

        int start = INT_MAX, end = INT_MIN;

        for(auto i: bloomDay){
            start = min(start, i);
            end = max(end, i);
        }

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(feasible(bloomDay, mid, m, k)) end = mid - 1;
            else start = mid + 1;
        }

        return start;
    }
};