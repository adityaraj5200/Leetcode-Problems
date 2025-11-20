// Approach:
// - Sort intervals by end ascending; if equal end, sort by start descending.
//   This ensures tighter intervals come first, helping greedy placement.
//
// - Maintain two markers:
//      firstPicked  -> smaller of the last two chosen points
//      secondPicked -> larger of the last two chosen points
//
// - For each interval [a, b]:
//      Case 1: firstPicked >= a
//          → Interval already has at least 2 chosen points. Do nothing.
//      Case 2: secondPicked >= a (only one point inside interval)
//          → Need 1 more point. Choose b as the new point.
//      Case 3: No points inside interval
//          → Need 2 new points. Choose (b-1) and b.
//
// - Greedy correctness: Always place new points as far right as possible (b or b-1)
//   to maximize overlap with future intervals.
//
// TC: O(n log n) due to sorting
// SC: O(1) extra space

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals: end ascending, start descending
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& A, const vector<int>& B) {
                 if (A[1] != B[1]) return A[1] < B[1];
                 return A[0] > B[0];
             });

        int result = 0;
        int firstPicked = -1;   // smaller of the last two chosen points
        int secondPicked = -1;  // larger of the last two chosen points

        for (auto& it : intervals) {
            int a = it[0];
            int b = it[1];

            // Case 1: Already have ≥2 points inside interval
            if (firstPicked >= a) {
                continue;
            }

            // Case 2: Only one point inside interval
            if (secondPicked >= a) {
                result += 1;
                firstPicked = secondPicked;
                secondPicked = b;   // choose b
                continue;
            }

            // Case 3: No point inside interval → add two points
            result += 2;
            firstPicked = b - 1;
            secondPicked = b;
        }

        return result;
    }
};
