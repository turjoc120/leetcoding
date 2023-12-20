class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy=prices[0], profit=0;
        for(auto i: prices){
            minBuy = min(minBuy, i);
            profit=max(profit, i-minBuy);
        }
        return profit;
    }
};