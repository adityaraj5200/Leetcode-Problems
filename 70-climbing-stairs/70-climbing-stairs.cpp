class Solution {
public:
    int climbStairs(int n) {
        int dp[2] = {1,2};
        if(n<=2) return dp[n-1];
        n -= 2;
        while(n--){
            int newValue = dp[0]+dp[1];
            dp[0] = dp[1];
            dp[1] = newValue;
        }
        
        return dp[1];
    }
};