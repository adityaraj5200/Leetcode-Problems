/**
 * Approach:
 * 1. We want to transform two strings into the same string by deleting characters.
 *    Deleting a character costs its ASCII value.
 * 2. This is equivalent to keeping a common subsequence and deleting all other chars.
 *    The maximum benefit comes from keeping a longest common subsequence (LCS)
 *    with the largest sum of kept ASCII values.
 * 3. Let dp[i][j] be the maximum ASCII sum of common subsequence of s1[0..i-1] and s2[0..j-1].
 * 4. Recurrence:
 *      - If s1[i-1] == s2[j-1], then dp[i][j] = dp[i-1][j-1] + ASCII(s1[i-1])
 *      - Else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 * 5. After computing dp, total ASCII sum of both strings is known.
 *    The minimum delete sum = totalSum(s1) + totalSum(s2) - 2 * dp[n1][n2],
 *    because dp[n1][n2] is the cost of the ASCII values we can keep.
 */

// Time & Space Complexity:
// Time Complexity: O(n1 * n2)
// Space Complexity: O(n1 * n2)
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        int[][] dp = new int[n1 + 1][n2 + 1];

        // Build dp for LCS of ASCII sums
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + s1.charAt(i - 1);
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int keepSum = dp[n1][n2];

        int totalSum = 0;
        for (int i = 0; i < n1; i++) {
            totalSum += s1.charAt(i);
        }
        for (int j = 0; j < n2; j++) {
            totalSum += s2.charAt(j);
        }

        return totalSum - 2 * keepSum;
    }
}
