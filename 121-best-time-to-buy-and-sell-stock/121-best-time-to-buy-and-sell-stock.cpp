class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size(), minBuy = INT_MAX;
        for(int i=0;i<n;i++){
            minBuy = min(minBuy, prices[i]);
            ans = max(ans, prices[i]-minBuy);
        }
        
        return ans;
    }
};