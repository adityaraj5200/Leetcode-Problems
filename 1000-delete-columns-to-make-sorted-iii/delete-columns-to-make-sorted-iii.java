/*
Approach:
- Each column can be viewed as a vector of characters across all rows.
- We want to keep the maximum number of columns such that, when read left to right,
  the rows are in non-decreasing lexicographical order.
- This becomes a Longest Non-Decreasing Subsequence (LNDS) problem on columns.
- Define dp[i] = maximum number of columns we can keep ending at column i.
- Column j can come before column i if:
    * For every row r: words[r][j] <= words[r][i]
  (No strict inequality is required; equality is allowed.)
- Compute dp using O(m^2) transitions, where m is the number of columns.
- The answer is total columns minus the maximum dp value.
*/

// Time Complexity: O(m * m * n)
// Space Complexity: O(m)

class Solution {
    public int minDeletionSize(String[] words) {
        int n = words.length;
        int m = words[0].length();

        int[] dp = new int[m];
        for (int i = 0; i < m; i++) dp[i] = 1;

        int maxKeep = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (canFollow(words, j, i)) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxKeep = Math.max(maxKeep, dp[i]);
        }

        return m - maxKeep;
    }

    private boolean canFollow(String[] words, int prev, int curr) {
        for (int r = 0; r < words.length; r++) {
            if (words[r].charAt(curr) < words[r].charAt(prev)) {
                return false;
            }
        }
        return true;
    }
}
