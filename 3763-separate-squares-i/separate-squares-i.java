/**
 * Approach:
 * 1. We are given squares defined by bottom-left (x, y) and side length l. Each has area l*l.
 * 2. We want to find the minimum horizontal line Y such that the total area below Y
 *    equals the total area above Y. Overlapping areas count separately for each square.
 * 3. Define two helper functions:
 *      - belowArea(Y): the total area of square portions strictly below the line y=Y.
 *      - aboveArea(Y): the total area strictly above the line y=Y.
 *    A square contributes:
 *      - 0 if Y <= yi (line is below entire square),
 *      - l*l if Y >= yi+l (line is above entire square),
 *      - otherwise a partial area.
 *    Partial areas:
 *      - below portion = (Y - yi) * l
 *      - above portion = (yi + l - Y) * l.
 * 4. Precompute totalArea = sum(l*l) for all squares; target half is totalArea/2.
 * 5. The function belowArea(Y) is continuous and non-decreasing in Y, so we can binary
 *    search over Y from the minimum y to the maximum (y + l) among all squares.
 * 6. At each mid Y, compute below area, compare with target half, and adjust
 *    the binary search bounds.
 * 7. After sufficient iterations, the low bound converges to the minimum Y where
 *    below area ≥ target, which is the answer within 1e-6 precision.
 */

// Time Complexity: O(n * log R) where R = range of candidate Ys  
// Space Complexity: O(1)
class Solution {
    public double separateSquares(int[][] squares) {
        int n = squares.length;
        double totalArea = 0.0;
        double minY = Double.POSITIVE_INFINITY;
        double maxY = 0.0;
        
        for (int[] s : squares) {
            double y = s[1];
            double l = s[2];
            totalArea += l * l;
            minY = Math.min(minY, y);
            maxY = Math.max(maxY, y + l);
        }
        double half = totalArea / 2.0;
        
        double lo = minY, hi = maxY;
        for (int it = 0; it < 100; it++) { // 100 iterations for 1e-6 precision
            double mid = (lo + hi) / 2.0;
            double below = 0.0;
            for (int[] s : squares) {
                double y = s[1], l = s[2];
                if (mid <= y) {
                    continue;
                } else if (mid >= y + l) {
                    below += l * l;
                } else {
                    below += (mid - y) * l;
                }
            }
            if (below < half) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
}
