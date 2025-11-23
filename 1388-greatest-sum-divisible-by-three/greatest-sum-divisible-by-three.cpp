// Approach:
// - We want the maximum sum of a subset of nums such that sum % 3 == 0.
// - Observe that any number x has remainder r = x % 3 (r in {0,1,2}).
// - We maintain dp[0], dp[1], dp[2]: the maximum sum we can achieve so far with remainder 0,1,2 respectively.
// - For each num in nums:
//     we consider adding it to each of the three previous states and update a new dp array:
//       newDp[(rPrev + num % 3) % 3] = max(newDp[(rPrev + num % 3) % 3], dp[rPrev] + num)
//     Also we can always skip num: newDp[rPrev] = max(newDp[rPrev], dp[rPrev])
// - At the end dp[0] is the answer (largest sum divisible by 3).
//
// Time Complexity: O(n) where n = nums.size()
// Space Complexity: O(1) extra space (just 3 variables for dp states)

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[0] = max sum with remainder 0
        // dp[1] = max sum with remainder 1
        // dp[2] = max sum with remainder 2
        int dp0 = 0, dp1 = INT_MIN, dp2 = INT_MIN;
        
        for (int x : nums) {
            int r = x % 3;
            int new0 = dp0, new1 = dp1, new2 = dp2;
            
            if (r == 0) {
                new0 = max(new0, dp0 + x);
                new1 = max(new1, dp1 + x);
                new2 = max(new2, dp2 + x);
            } else if (r == 1) {
                new1 = max(new1, dp0 + x);
                new2 = max(new2, dp1 + x);
                new0 = max(new0, dp2 + x);
            } else { // r == 2
                new2 = max(new2, dp0 + x);
                new0 = max(new0, dp1 + x);
                new1 = max(new1, dp2 + x);
            }
            
            dp0 = new0;
            dp1 = new1;
            dp2 = new2;
        }
        
        return dp0;
    }
};
