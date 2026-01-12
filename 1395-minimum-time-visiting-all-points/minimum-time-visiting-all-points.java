/**
 * Approach:
 * 1. We are given a list of 2D points and can move in 8 directions:
 *      - horizontally, vertically, or diagonally.
 *    Moving diagonally from (x1, y1) to (x1+1, y1+1) counts as one step.
 * 2. To go from one point to the next, the minimum number of steps needed
 *    is determined by how far apart they are in x and y.
 *    Because we can move diagonally, each diagonal move reduces both x and y
 *    differences by 1. After diagonal moves, we may still need straight moves.
 * 3. The key insight is that the minimum steps between (x1,y1) and (x2,y2)
 *    is:
 *       max(|x2 - x1|, |y2 - y1|)
 *    because diagonal moves cover both axes simultaneously.
 * 4. Sum this distance for each consecutive pair of points in the array.
 * 5. Return the total.
 */

// Time & Space Complexity:
// Time Complexity: O(n)  Space Complexity: O(1)
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int total = 0;
        for (int i = 1; i < points.length; i++) {
            int dx = Math.abs(points[i][0] - points[i - 1][0]);
            int dy = Math.abs(points[i][1] - points[i - 1][1]);
            total += Math.max(dx, dy);
        }
        return total;
    }
}
