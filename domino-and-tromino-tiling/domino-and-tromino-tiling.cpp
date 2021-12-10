class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;
        vector<unsigned int> dp(n+1,1);
        if(n>=2) dp[2] = 2;
        for(int i=3;i<=n;i++)
            dp[i] = (2*dp[i-1] + dp[i-3])%mod;
        return dp.back();
    }
};