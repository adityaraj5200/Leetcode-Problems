class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2] = {cost[0],cost[1]};
        for(int i=2;i<cost.size();i++){
            int newValue = cost[i] + min(dp[0],dp[1]);
            dp[0] = dp[1];
            dp[1] = newValue;
        }
        
        return min(dp[0],dp[1]);
    }
};