class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(n-1, k, false, dp);
    }

private:
    const int MOD = 1e9+7;

    int solve(int n, int k, bool isAddingLine, vector<vector<vector<int>>> &dp) {
        if(k < 0 || n < 0) return 0;
        if(n == 0 && k == 0 && !isAddingLine) return 1;

        int &res = dp[n][k][isAddingLine];
        if(res != -1) return res;

        if(isAddingLine) {
            int stopAdding = solve(n, k-1, false, dp);
            int keepAdding = solve(n-1, k, true, dp);
            return res = (stopAdding + keepAdding) % MOD;
        } else {
            int startAdding = solve(n-1, k, true, dp);
            int skip = solve(n-1, k, false, dp);
            return res = (startAdding + skip) % MOD;
        }
    }
};
