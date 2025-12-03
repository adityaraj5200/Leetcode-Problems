/*
    Approach:
    - A trapezoid is a convex quadrilateral with at least one pair of parallel sides.
    - Any pair of parallel sides comes from two distinct lines with the same slope.
      Each side itself is just a segment defined by 2 points on that line.
    - High-level idea:
        1) For every pair of points (i, j), build the line passing through them:
             - slope  k
             - intercept b  (for vertical lines we treat k as a special large value and b as x)
           This pair (k, b) uniquely identifies a line.
        2) On each such line, there can be multiple segments (different pairs of points).
           If a line with slope k and intercept b has t segments on it, then:
             - It contributes t “choices” for one side of the trapezoid.
        3) For each fixed slope k:
             - Collect all lines (k, b1), (k, b2), ...
             - Let their segment counts be t1, t2, ..., tm.
             - Any trapezoid with parallel sides of slope k comes from picking:
                   one segment from one line and one segment from a different parallel line.
               Number of ways for that slope:
                   sum over all unordered pairs of lines: ti * tj
               We can compute this efficiently with a running sum:
                   s = 0; for each t: result += s * t; s += t;
           This gives us ALL quadrilaterals formed by two non-coincident parallel lines.
           However, some of these are “self-crossing” / non-convex and should not be counted.
    - How to subtract the bad ones (self-crossing bow-ties):
        - In a self-crossing quadrilateral formed by 4 points, the two chosen segments
          that we think are "sides" might actually be the diagonals crossing at their midpoint.
        - Key property: both diagonals of such a configuration share the SAME midpoint.
        - So we:
            1) For every segment (i, j), compute its midpoint:
                   midX = x_i + x_j, midY = y_i + y_j  (we avoid division by just using sums).
               Encode this midpoint into a single integer key.
            2) Group segments by this midpoint key. Within each midpoint group, also group by slope.
               - For each midpoint p, we have counts per slope:
                     c1, c2, ..., ck
               - Any unordered pair of segments with the same midpoint but different slopes
                 corresponds to a “diagonal pair” of a self-crossing quadrilateral.
               - These have been overcounted in the previous step and must be subtracted.
               - Number of such bad pairs for that midpoint:
                     sum over unordered pairs of slopes: ci * cj
                 Again we can compute via a running sum:
                     s = 0; for each c: bad += s * c; s += c;
        - Final answer = (sum over all slopes of good parallel segment pairs)
                         - (sum over all midpoints of bad diagonal pairs).
    - We carefully handle vertical lines by using a sentinel slope (e.g. 1e9) and using x as "intercept".

    Time Complexity: O(n^2)       // we process all pairs of points
    Space Complexity: O(n^2)      // for storing line and midpoint group statistics
*/

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;

        // cntBySlopeAndIntercept[k][b] = number of segments whose supporting line has slope k and intercept b
        //   - lines with same (k, b) are the same geometric line
        //   - different b but same k => parallel distinct lines
        unordered_map<double, unordered_map<double, int>> cntBySlopeAndIntercept;

        // cntByMidpointAndSlope[midKey][k] = number of segments that have this midpoint and slope k
        //   - used to subtract self-crossing / diagonal-based configurations
        unordered_map<long long, unordered_map<double, int>> cntByMidpointAndSlope;

        cntBySlopeAndIntercept.reserve(n * n);
        cntByMidpointAndSlope.reserve(n * n);

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = 0; j < i; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                // Compute slope k and "intercept" b in double
                // For vertical lines: slope is a large sentinel, intercept is x-coordinate.
                double k;
                double b;
                if (dx == 0) {
                    k = 1e9;              // sentinel for vertical line
                    b = x1;               // line is x = x1
                } else {
                    k = 1.0 * dy / dx;    // regular slope
                    // For line y = kx + c, we use an equivalent stable form:
                    //   (y1 * dx - x1 * dy) / dx
                    // This avoids repeated floating error from computing c = y - kx directly.
                    b = 1.0 * (1LL * y1 * dx - 1LL * x1 * dy) / dx;
                }

                // Count this segment under its line (k, b)
                cntBySlopeAndIntercept[k][b] += 1;

                // Encode midpoint: (x1 + x2, y1 + y2)
                // Coordinates in [-1000,1000] => sums in [-2000,2000]
                // Shift by +2000 to make non-negative, and pack into one 64-bit integer.
                int midXsum = x1 + x2 + 2000;
                int midYsum = y1 + y2 + 2000;
                long long midKey = 1LL * midXsum * 4000 + midYsum;

                // Count this segment under its midpoint and slope
                cntByMidpointAndSlope[midKey][k] += 1;
            }
        }

        long long ans = 0;

        // 1) Count all pairs of segments that lie on distinct parallel lines (same slope, different intercept)
        //    For a fixed slope:
        //      - lines: L1, L2, ..., Lm
        //      - counts of segments per line: t1, t2, ..., tm
        //      - number of pairs of segments on different lines:
        //            sum over unordered pairs (a < b): ta * tb
        //      - compute via running sum: s = 0; for each t: ans += s * t; s += t;
        for (auto &slopeEntry : cntBySlopeAndIntercept) {
            auto &byIntercept = slopeEntry.second;
            int prefixSum = 0;  // sum of t's we've seen so far for this slope

            for (auto &interceptEntry : byIntercept) {
                int segmentCountOnThisLine = interceptEntry.second;
                ans += 1LL * prefixSum * segmentCountOnThisLine;
                prefixSum += segmentCountOnThisLine;
            }
        }

        // 2) Subtract bad configurations where chosen two segments are actually diagonals
        //    of a self-crossing quadrilateral (bow-tie), which share the same midpoint.
        //    For a fixed midpoint:
        //      - segments grouped by slope: counts c1, c2, ..., ck
        //      - unordered pairs with that midpoint but different slope:
        //            sum over unordered pairs (a < b): ca * cb
        //      - again via running sum.
        for (auto &midEntry : cntByMidpointAndSlope) {
            auto &bySlope = midEntry.second;
            int prefixSum = 0;

            for (auto &slopeCountEntry : bySlope) {
                int countWithThisSlope = slopeCountEntry.second;
                ans -= 1LL * prefixSum * countWithThisSlope;
                prefixSum += countWithThisSlope;
            }
        }

        return (int)ans;
    }
};
