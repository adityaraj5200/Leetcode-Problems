/**
 * Approach:
 * 1. We are given an array of bar heights and need the largest rectangle in the histogram.
 * 2. Use a monotonic increasing stack that stores indices of bars.
 *    - The stack’s heights (by index) will be in non-decreasing order.
 * 3. Iterate through all indices from 0 to n inclusive (we use n as a sentinel):
 *    a. Let curHeight = (i == n ? 0 : heights[i]).
 *    b. While the stack is not empty and curHeight is less than the height
 *       at stack.peek(), we can finalize rectangles for bars that are taller
 *       than curHeight:
 *       - Pop the top index as heightIndex.
 *       - height = heights[heightIndex].
 *       - The right boundary for this height is i − 1.
 *       - The left boundary is:
 *           • 0 if the stack is now empty (no smaller bar to the left),
 *           • stack.peek() + 1 otherwise (first bar to the right of the smaller left bar).
 *       - width = right − left + 1.
 *       - area = height * width; update maxArea.
 *    c. Push the current index onto the stack.
 * 4. The sentinel at i == n with height 0 ensures all bars are processed.
 * 5. Return the maximum rectangle area found.
 */

// Time Complexity: O(n)  Space Complexity: O(n)
class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        int n = heights.length;

        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n ? 0 : heights[i]);

            while (!stack.isEmpty() && curHeight < heights[stack.peek()]) {
                int heightIndex = stack.pop();
                int height = heights[heightIndex];

                int right = i - 1;
                int left = stack.isEmpty() ? 0 : stack.peek() + 1;
                int width = right - left + 1;

                maxArea = Math.max(maxArea, height * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
}
