class Solution {
public:
    bool feasible(vector<int> weights, int mid, int days){
        int sum = 0, myDays = 0;
        for(auto i: weights){
            if(sum + i > mid){
                myDays++;
                sum = i;
            }  
            else sum+=i;
        }
        myDays++;
        return myDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = INT_MIN, end = 0;
        for(auto i: weights){
            start = max(start, i);
            end +=i;
        }

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(feasible(weights, mid, days)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};