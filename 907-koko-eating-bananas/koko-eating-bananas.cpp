class Solution {
public:
    long long totalHours(vector<int> piles, long long mid){
        long long hours = 0;
        for(auto i: piles){
            hours += ceil((double)i / (double)mid);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = -1;
        for(auto i: piles) end = max(end, i);

        while(start <= end){
            long long mid = start + (end - start) / 2;
            //decrese the eating amount
            long long val =totalHours(piles, mid);
            if(val <= h) end = mid - 1;
            //increase the eating amount 
            else start = mid + 1;
        }     
        return start;
    }
};