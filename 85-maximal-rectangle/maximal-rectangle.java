/**
 * Approach:
 * 1. We transform the matrix into a series of histogram heights.
 *    For each row:
 *      - If cell == '1', increase height at that column by 1.
 *      - If cell == '0', reset height at that column to 0.
 * 2. For each row’s heights[] array, compute the largest rectangle in the histogram.
 *    Use a monotonic increasing stack of column indices:
 *      - Push indices while current height is >= stack top’s height.
 *      - When we see a smaller height, pop from the stack and compute area:
 *          height = heights[popped],
 *          width = current index − stack top after pop − 1
 *      - Repeat until stack is valid.
 * 3. Track the maximum area seen across all rows.
 * 4. Time is O(rows * cols), as each histogram computation is linear with a stack.
 */

// Time Complexity: O(m * n)  Space Complexity: O(n)
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        int m = matrix.length, n = matrix[0].length;
        int[] heights = new int[n];
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            // Build histogram heights for this row
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = Math.max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    private int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0, n = heights.length;
        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n ? 0 : heights[i]);
            while (!stack.isEmpty() && curHeight < heights[stack.peek()]) {
                int height = heights[stack.pop()];
                int widthRightBoundary = i-1;
                int widthLeftBoundary = stack.empty() ? 0 : stack.peek()+1;
                int width = widthRightBoundary-widthLeftBoundary+1;
                maxArea = Math.max(maxArea, height * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
}
