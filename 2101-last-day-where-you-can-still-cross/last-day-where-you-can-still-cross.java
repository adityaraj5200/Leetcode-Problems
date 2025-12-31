/**
 * Approach:
 * 1. We are given a list of cells that become flooded day by day.
 *    On day `k`, the first `k` cells in `cells` are water (1) and others remain land (0). :contentReference[oaicite:0]{index=0}
 * 2. We want to find the **last day** on which it is still possible to walk
 *    from any cell in the top row to any cell in the bottom row using only land,
 *    moving in the 4 cardinal directions. :contentReference[oaicite:1]{index=1}
 * 3. This problem has a **monotonic property**:
 *    - If we can cross on day `d`, then we can also cross on any earlier day
 *      because fewer cells are flooded.
 *    - If we *cannot* cross on day `d`, we cannot cross on any later day.
 * 4. Use **binary search** on days from 1 to `cells.length`:
 *    - For each mid day `m`, simulate the grid by marking the first `m` flooded cells.
 *    - Run a **BFS** from all land cells in the top row and check if we can reach
 *      any land cell in the bottom row.
 * 5. If crossing is possible on day `m`, move search right (later days), else
 *    move left. The answer is the last `m` such that crossing is possible.
 */

// Time Complexity: O((row * col) * log(row * col))
//   - binary search over days times BFS (row*col) per check.
// Space Complexity: O(row * col)
class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        int left = 1, right = cells.length, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canCross(row, col, cells, mid)) {
                ans = mid;        // mid is possible, try later days
                left = mid + 1;
            } else {
                right = mid - 1;  // cannot cross on mid, try earlier
            }
        }
        return ans;
    }

    // Check if we can cross from top to bottom on day `day`
    private boolean canCross(int row, int col, int[][] cells, int day) {
        // Build grid for current day
        int[][] grid = new int[row][col];
        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1; // flooded
        }

        Queue<int[]> q = new ArrayDeque<>();
        // Add all land cells in top row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.offer(new int[]{0, j});
                grid[0][j] = 1; // mark visited
            }
        }

        // 4-direction movement
        int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int r = cell[0], c = cell[1];
            if (r == row - 1) return true; // reached bottom row
            for (int[] d : DIRS) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    q.offer(new int[]{nr, nc});
                    grid[nr][nc] = 1; // mark visited
                }
            }
        }
        return false;
    }
}
