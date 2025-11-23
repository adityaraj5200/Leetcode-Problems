// Approach:
// We want the minimum number of jumps to reach the last index.
// Use a greedy “range expansion” method: track the farthest index we can reach (farthest),
// and track the end of the current jump’s range (endOfCurrentJump).
// As we iterate i from 0 to n-2:
//   - Update farthest = max(farthest, i + nums[i]).
//   - If i reaches endOfCurrentJump, we must make a jump:
//       jumps++
//       endOfCurrentJump = farthest
// This effectively means: we used one more jump and our new jump can reach at least farthest.
// At the end, jumps is the answer.
// TC: O(n) where n = nums.size()
// SC: O(1) extra space

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int endOfCurrentJump = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == endOfCurrentJump) {
                ++jumps;
                endOfCurrentJump = farthest;
                if (endOfCurrentJump >= n - 1) break;
            }
        }
        return jumps;
    }
};
