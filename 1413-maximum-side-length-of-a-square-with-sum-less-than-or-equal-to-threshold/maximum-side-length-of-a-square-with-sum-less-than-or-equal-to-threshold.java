/**
 * Approach:
 * 1. We want the maximum possible side‐length k of a square in mat such that
 *    the sum of its elements is <= threshold.
 * 2. Use a 2D prefix sum array so we can compute the sum of any k×k square in O(1).
 *    Let prefix[i][j] store the sum of the rectangle from (0,0) up to (i-1,j-1).
 * 3. Binary search on k from 1 to min(m, n):
 *    a) For a candidate size mid, check all possible k×k squares:
 *       - For each top‐left (i,j), compute sum using prefix and see if <= threshold.
 *    b) If any square of side mid is valid, mid is feasible → search larger.
 *       Otherwise mid is too large → search smaller.
 * 4. Return the largest feasible k.
 */

// Time Complexity: O(m * n * log(min(m,n)))
// Space Complexity: O(m * n)
class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length, n = mat[0].length;

        // Build prefix sums
        int[][] prefix = new int[m + 1][n + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = mat[i][j]
                    + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }

        int lo = 0, hi = Math.min(m, n);
        int ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canFindSquare(prefix, threshold, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private boolean canFindSquare(int[][] prefix, int threshold, int k) {
        if (k <= 0) return true;
        int m = prefix.length - 1;
        int n = prefix[0].length - 1;
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                int total = prefix[i + k][j + k]
                    - prefix[i][j + k] - prefix[i + k][j]
                    + prefix[i][j];
                if (total <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
}
