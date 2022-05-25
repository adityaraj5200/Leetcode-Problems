class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size(), maxval = INT_MIN;
        vector<int> dp(n);
        for(int i=n-1;i>=0;i--){
            dp[i] = maxval = max(maxval, prices[i]);
        }
        
        for(int i=0;i<n-1;i++){
            ans = max(ans, dp[i+1]-prices[i]);
        }
        
        return ans;
    }
};