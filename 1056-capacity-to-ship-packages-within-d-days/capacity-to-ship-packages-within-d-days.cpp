class Solution {
public:
    bool feasible(vector<int> weights, int mid, int days){
        int possDays = 0, weightSum = 0;
        for(auto i: weights){
            if(weightSum + i > mid){
                possDays++;
                weightSum = i;
            } 
            else weightSum += i;
        }
        if(weightSum != 0) possDays++;
        return possDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = INT_MIN, end=0;

        for(auto i: weights){
            start = max(start, i);
            end +=i;
        }

        while(start <= end){
            int mid = (start + end) / 2;
            if(feasible(weights, mid, days)) end = mid - 1;
            else start = mid + 1;
        }

        return start;
    }
};