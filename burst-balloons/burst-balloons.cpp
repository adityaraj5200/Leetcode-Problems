class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> vals(2, 1); 
        vals.insert(vals.begin()+1, nums.begin(), nums.end()); 
        int n = vals.size(); 
        vector<vector<int>> dp(n, vector<int>(n)); 
        for (int i = n-1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                for (int k = i+1; k < j; ++k)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + vals[i]*vals[k]*vals[j]); 
        return dp[0].back(); 
    }
};