class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start =0, end = arr.size()-1;
        if(arr[0] > k) return k;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] - (mid+1) < k) start = mid + 1;
            else end = mid - 1;  
        }
        int item = arr[end];
        k-=item - (end+1);
        while(k--) item++;
        return item;
    }
};