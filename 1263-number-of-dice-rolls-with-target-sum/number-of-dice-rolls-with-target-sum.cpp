class Solution {
private:
    vector<vector<int>> dp;
    const int MOD = 1e9+7;

    int solve(int n,int k,int target){
        if(n==0) return target==0 ? 1 : 0;
        if(target<0) return 0;

        if(dp[n][target] != -1) return dp[n][target];

        long long numWays = 0;
        for(int i=1;i<=k;i++){
            numWays = (numWays+solve(n-1,k,target-i))%MOD;
        }

        return dp[n][target] = numWays;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n+1,vector<int>(target+1,-1));
        return solve(n,k,target);
    }
};