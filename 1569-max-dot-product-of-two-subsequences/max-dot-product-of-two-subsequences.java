/**
 * Approach:
 * 1. We need the maximum dot product of two **non-empty** subsequences from nums1 and nums2.
 * 2. Use recursion with memoization (top-down DP).
 * 3. Define a recursive function dfs(i, j) that returns the maximum dot product
 *    using subsequences starting from index i in nums1 and index j in nums2,
 *    with the constraint that we must pick at least one pair.
 * 4. At position (i, j), we have three choices:
 *    a) Take nums1[i] and nums2[j] as a pair:
 *       - Either start a new subsequence with their product
 *       - Or extend a previously chosen subsequence
 *    b) Skip nums1[i] → dfs(i + 1, j)
 *    c) Skip nums2[j] → dfs(i, j + 1)
 * 5. The best answer at (i, j) is the maximum of these choices.
 * 6. Use memoization to avoid recomputation.
 * 7. Base case: if either array is exhausted, return a very small value
 *    (invalid because subsequence must be non-empty).
 */

// Time & Space Complexity:
// Time Complexity: O(n1 * n2)
// Space Complexity: O(n1 * n2) (memo table + recursion stack)
class Solution {
    private int[] nums1, nums2;
    private Integer[][] memo;
    private static final int NEG_INF = Integer.MIN_VALUE / 2;

    public int maxDotProduct(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        memo = new Integer[nums1.length][nums2.length];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        // If we reached the end of either array, no valid non-empty subsequence possible
        if (i == nums1.length || j == nums2.length) {
            return NEG_INF;
        }

        if (memo[i][j] != null) {
            return memo[i][j];
        }

        int product = nums1[i] * nums2[j];

        // Option 1: take both elements (start new OR extend existing)
        int takeBoth = Math.max(
            product,
            product + dfs(i + 1, j + 1)
        );

        // Option 2: skip nums1[i]
        int skipFirst = dfs(i + 1, j);

        // Option 3: skip nums2[j]
        int skipSecond = dfs(i, j + 1);

        // Choose the best among all options
        int best = Math.max(takeBoth, Math.max(skipFirst, skipSecond));
        memo[i][j] = best;
        return best;
    }
}
