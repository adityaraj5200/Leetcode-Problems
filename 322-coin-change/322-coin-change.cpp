class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        
        for(long long i=0;i<=amount;i++){
            for(int &val: coins){
                long long j = i+val;
                if(j > amount) break;
                dp[j] = min(dp[j], dp[i]+1);
            }
        }
        
        return dp[amount]==1e9 ? -1 : dp[amount];
    }
};