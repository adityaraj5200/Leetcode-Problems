/*
Approach:
1. We want the k-th smallest element in an n×n matrix where each row and each column is sorted.
2. A common and efficient approach is to binary search on the **value range** rather than indices.
   - Let low = smallest value in matrix (matrix[0][0]).
   - Let high = largest value in matrix (matrix[n-1][n-1]).
3. For each mid in [low, high], count how many elements in the matrix are ≤ mid.
   - Because rows and columns are sorted, we can count in O(n) time by scanning from bottom-left
     corner upwards/rightwards in a "staircase" fashion:
       * Start at (row = n-1, col = 0).
       * If matrix[row][col] ≤ mid, then all elements above it in this column are ≤ mid,
         so add (row + 1) to the count and move right.
       * Else move up.
4. If count < k, we need a larger mid → low = mid + 1; else we shrink high = mid.
5. When low meets high, that is the k-th smallest value.

Time Complexity: O(n * log(maxVal - minVal)) where counting ≤ mid is O(n)
Space Complexity: O(1)
*/

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    private int countLessEqual(int[][] matrix, int target) {
        int n = matrix.length;
        int row = n - 1, col = 0, count = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }

        return count;
    }
}
