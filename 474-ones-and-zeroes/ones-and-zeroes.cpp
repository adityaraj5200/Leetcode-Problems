/*
Approach:
- This is a 0/1 Knapsack variant with two constraints: number of 0s (m) and number of 1s (n).
- Each string can either be included (if it fits in remaining m and n) or excluded.
- Use recursion with memoization:
    helper(i, m, n) → maximum number of strings we can form using strs[i..end]
                      with at most m zeros and n ones.
- Transition:
    skip = helper(i+1, m, n)
    take = 1 + helper(i+1, m - zeros[i], n - ones[i]) if feasible
    dp[i][m][n] = max(take, skip)
- Base case: when i == size of strs → return 0.

Time Complexity: O(len * m * n)
Space Complexity: O(len * m * n) (for 3D DP table)
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        dp.assign(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        vector<pair<int,int>> counts(len);

        // Precompute zeros and ones for each string
        for(int i=0; i<len; i++){
            int zeros = 0, ones = 0;
            for(char c: strs[i]){
                if(c == '0') zeros++;
                else ones++;
            }
            counts[i] = {zeros, ones};
        }

        return helper(0, m, n, counts);
    }

private:
    vector<vector<vector<int>>> dp;

    int helper(int i, int m, int n, vector<pair<int,int>>& counts){
        if(i == counts.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];

        int skip = helper(i+1, m, n, counts);
        int take = 0;
        int zeros = counts[i].first, ones = counts[i].second;

        if(m >= zeros && n >= ones){
            take = 1 + helper(i+1, m - zeros, n - ones, counts);
        }

        return dp[i][m][n] = max(take, skip);
    }
};
