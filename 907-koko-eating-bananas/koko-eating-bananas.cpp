class Solution {
public:
    bool totalHours(vector<int> piles, int mid, int h){
        long long hours = 0;
        for(auto i: piles){
            hours += ceil((double)i / (double)mid);
            if(hours > h) return false;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = -1;
        for(auto i: piles) end = max(end, i);

        while(start <= end){
            long long mid = start + (end - start) / 2;
            //decrese the eating amount
            if(totalHours(piles, mid, h)) end = mid - 1;
            //increase the eating amount 
            else start = mid + 1;
        }     
        return start;
    }
};