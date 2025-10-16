// Time Complexity: O(n * k * target)
// Space Complexity: O(n * target) + O(n) recursion stack

class Solution {
public:
    const int MOD=1e9+7;
    vector<vector<int>> dp;

    int solve(int dice,int faces,int target){
        if(target<0) return 0;
        if(dice==0) return target==0 ? 1 : 0;

        if(dp[dice][target]!=-1) return dp[dice][target];

        long long ways=0;
        for(int i=1;i<=faces;i++){
            ways=(ways+solve(dice-1,faces,target-i))%MOD;
        }
        return dp[dice][target]=ways;
    }

    int numRollsToTarget(int n,int k,int target){
        dp.assign(n+1,vector<int>(target+1,-1));
        return solve(n,k,target);
    }
};
