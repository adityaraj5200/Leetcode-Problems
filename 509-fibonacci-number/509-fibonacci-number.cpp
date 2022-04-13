class Solution {
public:
    int fib(int n) {
        int dp[2] = {0,1};
        if(n<=1) return dp[n];
        while(n>=2){
            int newvalue = dp[0]+dp[1];
            dp[0] = dp[1];
            dp[1] = newvalue;
            n--;
        }
        
        return dp[1];
    }
};