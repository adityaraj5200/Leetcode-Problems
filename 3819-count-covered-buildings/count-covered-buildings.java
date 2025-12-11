/*
Approach:
1. We need to count buildings that have at least one neighbor in all four directions:
   - left (same row, smaller y)
   - right (same row, larger y)
   - below (same column, smaller x)
   - above (same column, larger x)
2. For each row x, track the minimum and maximum y of buildings in that row.
   For each column y, track the minimum and maximum x of buildings in that column.
3. Then for each building (x, y), if:
       minRowY[x] < y < maxRowY[x]  AND
       minColX[y] < x < maxColX[y]
   then it has neighbors on both sides horizontally AND vertically, so it's covered.
4. Use arrays of size n+1 (1-based coordinates) and update min/max values in one pass,
   then count covered buildings in another pass.

Time Complexity: O(m) where m = buildings.length  
Space Complexity: O(n) where n is grid dimension
*/
class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        // Track horizontal extents (per row)
        int[] minRowY = new int[n+1];
        int[] maxRowY = new int[n+1];
        // Track vertical extents (per column)
        int[] minColX = new int[n+1];
        int[] maxColX = new int[n+1];
        
        // Initialize
        java.util.Arrays.fill(minRowY, Integer.MAX_VALUE);
        java.util.Arrays.fill(maxRowY, Integer.MIN_VALUE);
        java.util.Arrays.fill(minColX, Integer.MAX_VALUE);
        java.util.Arrays.fill(maxColX, Integer.MIN_VALUE);
        
        // Compute min and max positions for each row and column
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            minRowY[x] = Math.min(minRowY[x], y);
            maxRowY[x] = Math.max(maxRowY[x], y);
            minColX[y] = Math.min(minColX[y], x);
            maxColX[y] = Math.max(maxColX[y], x);
        }
        
        int covered = 0;
        // Count covered buildings
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            if (minRowY[x] < y && y < maxRowY[x] &&
                minColX[y] < x && x < maxColX[y]) {
                covered++;
            }
        }
        
        return covered;
    }
}