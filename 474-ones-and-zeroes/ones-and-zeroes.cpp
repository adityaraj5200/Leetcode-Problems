// TC: O(L*m*n) where L = size of strs, m = available 0s, n = available 1s
// SC: O(m*n)
// Approach: This is a variation of 0/1 Knapsack. Each string has a cost (count of 0s & 1s) and a value (1).
// We use DP where dp[i][j] = max strings formed with i zeros and j ones.
// For each string, we iterate backwards (to avoid reuse) and update dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]).


class Solution {
public:
    int findMaxForm(vector<string>&strs,int m,int n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(string&s:strs){
            int zeros=count(s.begin(),s.end(),'0');
            int ones=s.size()-zeros;
            for(int i=m;i>=zeros;--i){
                for(int j=n;j>=ones;--j){
                    dp[i][j]=max(dp[i][j],1+dp[i-zeros][j-ones]);
                }
            }
        }

        return dp[m][n];
    }
};