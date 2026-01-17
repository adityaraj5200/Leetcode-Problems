/**
 * Approach:
 * 1. We are given n axis-aligned rectangles defined by bottom-left and top-right corners.
 *    We need the largest square that can fit inside the intersection of any two rectangles.
 * 2. For each pair (i, j) with i < j:
 *      - Compute the intersection rectangle between rectangle i and rectangle j:
 *          * width  = min(x2_i, x2_j) - max(x1_i, x1_j)
 *          * height = min(y2_i, y2_j) - max(y1_i, y1_j)
 *      - If both width and height are > 0, there is a valid overlapping region.
 *      - The largest square that fits inside this region has side = min(width, height).
 *      - Compute its area = side * side, and track the maximum across all pairs.
 * 3. If no valid intersection exists for any pair, return 0.
 */

// Time & Space Complexity:
// Time Complexity: O(n^2)  Space Complexity: O(1)
class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.length;
        long maxArea = 0;

        for (int i = 0; i < n; i++) {
            int x1a = bottomLeft[i][0];
            int y1a = bottomLeft[i][1];
            int x2a = topRight[i][0];
            int y2a = topRight[i][1];

            for (int j = i + 1; j < n; j++) {
                int x1b = bottomLeft[j][0];
                int y1b = bottomLeft[j][1];
                int x2b = topRight[j][0];
                int y2b = topRight[j][1];

                int overlapW = Math.min(x2a, x2b) - Math.max(x1a, x1b);
                int overlapH = Math.min(y2a, y2b) - Math.max(y1a, y1b);

                int side = Math.min(overlapW, overlapH);
                if (side > 0) {
                    long area = 1L * side * side;
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
        return maxArea;
    }
}