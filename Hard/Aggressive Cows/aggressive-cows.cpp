//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool feasible(vector<int> &stalls, int mid, int k){
        int last = stalls[0];
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - last >= mid){
                last = stalls[i];
                k--;
            }
            if(k<=0) break;
        }
        return k == 0;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        
        int start = 0, end = stalls[n-1] - stalls[0];
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(feasible(stalls, mid, k-1)) start = mid +1;
            else end = mid - 1;
        }
        
        return end;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends