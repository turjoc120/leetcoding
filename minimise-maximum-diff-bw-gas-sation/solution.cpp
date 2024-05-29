#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMnay(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int i = 0; i < k; i++)
    {
        int idx = pq.top().second;
        pq.pop();
        long double secLen = arr[idx + 1] - arr[idx];
        long double newLen = secLen / (long double)(howMnay[idx] + 2);
        howMnay[idx]++;
        pq.push({newLen, idx});
    }
    return pq.top().first;
}
