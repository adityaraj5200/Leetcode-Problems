// Approach:
// - We're looking at all paths from top-left to bottom-right by only moving down or right.
// - We only care whether the path sum is divisible by k — so we track the sum **mod k** instead of full sum.
// - Use dynamic programming: dp[i][j][r] = number of paths to cell (i,j) whose path-sum modulo k = r.
// - Transitions: coming into (i,j) from above or left, we add grid[i][j] to previous remainder, mod k.
// - Finally the answer is dp[m-1][n-1][0] (modulo 1e9+7).
// TC: O(m * n * k) where m,n = grid dims, k = divisor  
// SC: O(m * n * k) for dp table + O(1) extra  

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();
        // dp[r] for current row j; dp_next for next
        // We'll use 3-D table dp[i][j][r]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        
        dp[0][0][ grid[0][0] % k ] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    int ways = dp[i][j][r];
                    if (!ways) continue;
                    // from (i,j) go down
                    if (i + 1 < m) {
                        int nr = (r + grid[i+1][j]) % k;
                        dp[i+1][j][nr] = (dp[i+1][j][nr] + ways) % MOD;
                    }
                    // from (i,j) go right
                    if (j + 1 < n) {
                        int nr = (r + grid[i][j+1]) % k;
                        dp[i][j+1][nr] = (dp[i][j+1][nr] + ways) % MOD;
                    }
                }
            }
        }
        
        return dp[m-1][n-1][0];
    }
};
