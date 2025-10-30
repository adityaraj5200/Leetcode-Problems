// Time Complexity: O(m * n), where m = number of rows, n = number of columns
// Space Complexity: O(n)

// Approach:
// • Treat each row as the base of a histogram: compute heights of consecutive '1's up to that row.
// • For each row’s histogram, compute the largest rectangle area (using stack in O(n) time).
// • Keep track of the maximum rectangle found across all rows.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            // update histogram heights
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // compute largest rectangle area in this histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n ? 0 : heights[i]);
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};