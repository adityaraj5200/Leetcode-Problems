/**
 * Approach:
 * 1. A k x k magic square requires:
 *    - All k row sums equal
 *    - All k column sums equal
 *    - Both diagonals equal to the same value
 *    (values do NOT need to be distinct).
 * 2. Precompute prefix sums for rows and columns so that:
 *    - Row sum of grid[r][c..c+k-1] can be obtained in O(1)
 *    - Column sum of grid[r..r+k-1][c] can be obtained in O(1)
 * 3. Try square sizes from largest possible (min(m, n)) down to 2.
 *    - We iterate from large to small so we can return immediately
 *      when we find the largest valid magic square.
 * 4. For each k and each possible top-left corner (i, j):
 *    a) Compute the target sum using the first row.
 *    b) Check all remaining rows and columns using prefix sums.
 *    c) Check both diagonals explicitly in O(k).
 *    d) If all checks pass, this k is valid → return k.
 * 5. If no k >= 2 works, return 1 (every 1x1 cell is a magic square).
 */

// Time Complexity: O(m * n * min(m, n))
// Space Complexity: O(m * n)
class Solution {
    public int largestMagicSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        // Prefix sums for rows and columns
        int[][] rowPrefix = new int[m][n + 1];
        int[][] colPrefix = new int[n][m + 1];

        // Build row prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPrefix[i][j + 1] = rowPrefix[i][j] + grid[i][j];
            }
        }

        // Build column prefix sums
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colPrefix[j][i + 1] = colPrefix[j][i] + grid[i][j];
            }
        }

        // Try sizes from largest to smallest
        for (int k = Math.min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isMagic(grid, rowPrefix, colPrefix, i, j, k)) {
                        return k;
                    }
                }
            }
        }

        return 1; // At least 1x1 is always magic
    }

    private boolean isMagic(int[][] grid, int[][] rowPrefix, int[][] colPrefix,
                            int r, int c, int k) {

        // Target sum = sum of first row
        int target = rowPrefix[r][c + k] - rowPrefix[r][c];

        // Check all rows
        for (int i = 0; i < k; i++) {
            int sum = rowPrefix[r + i][c + k] - rowPrefix[r + i][c];
            if (sum != target) return false;
        }

        // Check all columns
        for (int j = 0; j < k; j++) {
            int sum = colPrefix[c + j][r + k] - colPrefix[c + j][r];
            if (sum != target) return false;
        }

        // Check main diagonal
        int diag1 = 0;
        for (int d = 0; d < k; d++) {
            diag1 += grid[r + d][c + d];
        }
        if (diag1 != target) return false;

        // Check anti-diagonal
        int diag2 = 0;
        for (int d = 0; d < k; d++) {
            diag2 += grid[r + d][c + k - 1 - d];
        }
        if (diag2 != target) return false;

        return true;
    }
}
