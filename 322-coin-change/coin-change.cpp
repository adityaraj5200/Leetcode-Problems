class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<int> dp(amount+1,1e9);
        dp[0] = 0;
        for(int& coin: coins){
            for(int i=0;i<=amount;i++){
                if(dp[i] == 1e9) continue;
                if(i+coin > amount) break;
                dp[i+coin] = min(dp[i+coin], 1+dp[i]);
            }
        }

        return dp[amount]==1e9 ? -1 : dp[amount];
    }
};