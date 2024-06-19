//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool feasible(vector<int> arr, int k, double mid){
        int stations = 0;
        for(int i =0; i< arr.size()-1; i++){
            stations+= ceil((arr[i+1] - arr[i]) / mid) -1;
            if(stations > k) break;
        }
        return stations <= k;
    }
    
    double findSmallestMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        long double start = 0, end= arr[n-1] - arr[0];
        
        while(end - start > 1e-6){
            double mid = (start + end) / 2.0;
            if(feasible(arr, k, mid)) end = mid;
            else start = mid;
        }
        return end;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends