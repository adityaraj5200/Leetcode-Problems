class Solution {
public:
    int numSquares(int num) {
        vector<int> dp(num+1,INT_MAX/10);
        dp[0] = 0;
        for(int i=1;i*i<=num;i++){
            for(int j=i*i;j<=num;j++){
                dp[j] = min(dp[j],dp[j-i*i]+1);
            }
        }
        
        return dp.back();
    }
};
