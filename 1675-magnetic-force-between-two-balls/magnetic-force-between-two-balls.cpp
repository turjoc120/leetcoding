class Solution {
public:
    bool feasible(vector<int>arr, int m, int mid){
        int last = arr[0], count = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - last >= mid){
                count++;
                last = arr[i];
            }
            if(count >= m) break;
        }
        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int start = 0, end = position[n-1] - position[0];

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(feasible(position, m, mid)) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
};