class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp = {0,1,1};
        if(n<3) return dp[n];
        n -= 2;
        while(n--){
            int newval = dp[0]+dp[1]+dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = newval;
        }
        return dp.back();
    }
};