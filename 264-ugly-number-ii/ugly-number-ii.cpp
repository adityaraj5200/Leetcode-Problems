class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;

        int p2=1,p3=1,p5=1;
        for(int i=2;i<=n;i++){
            int minval = min({dp[p2]*2,dp[p3]*3,dp[p5]*5});
            dp[i] = minval;
            if(minval == dp[p2]*2) p2++;
            if(minval == dp[p3]*3) p3++;
            if(minval == dp[p5]*5) p5++;
        }
        
        return dp[n];
    }
};