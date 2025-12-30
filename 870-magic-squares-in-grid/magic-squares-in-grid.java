/**
 * Approach:
 * 1. A 3x3 magic square has values 1 through 9 exactly once and every row,
 *    column, and both diagonals sum to 15.
 * 2. Loop through all possible 3x3 submatrices of the given grid.
 * 3. For each 3x3 block:
 *    a. Check that it contains all distinct values from 1 to 9.
 *    b. Compute sums of all 3 rows, 3 columns, and 2 diagonals.
 *    c. If all sums are 15, it’s a magic square.
 * 4. Count and return how many 3x3 magic squares are found.
 */

// Time Complexity: O(m * n * 1) = O(m * n) since each 3x3 check is constant time.
// Space Complexity: O(1) (only fixed-size counters/arrays used).
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int count = 0;

        // Loop over top-left corner of each possible 3x3 submatrix
        for (int r = 0; r + 2 < rows; r++) {
            for (int c = 0; c + 2 < cols; c++) {
                if (isMagic(grid, r, c)) {
                    count++;
                }
            }
        }

        return count;
    }

    // Check if the 3x3 submatrix with top-left at (r, c) is a magic square
    private boolean isMagic(int[][] g, int r, int c) {
        boolean[] seen = new boolean[10]; // 1..9

        // Check distinct numbers 1–9
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = g[r + i][c + j];
                if (val < 1 || val > 9 || seen[val]) {
                    return false;
                }
                seen[val] = true;
            }
        }

        // Check all rows sum to 15
        for (int i = 0; i < 3; i++) {
            int sum = g[r + i][c] + g[r + i][c + 1] + g[r + i][c + 2];
            if (sum != 15) return false;
        }

        // Check all columns sum to 15
        for (int j = 0; j < 3; j++) {
            int sum = g[r][c + j] + g[r + 1][c + j] + g[r + 2][c + j];
            if (sum != 15) return false;
        }

        // Check diagonals sum to 15
        int d1 = g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2];
        int d2 = g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c];
        if (d1 != 15 || d2 != 15) return false;

        return true;
    }
}
