/*
    Approach:
    - Let dp[i] = number of ways to partition first i elements (nums[0..i-1]).
    - Use sliding window [left..i-1] to ensure any segment ending at i-1 has max-min ≤ k.
    - Maintain two deques to track current window's min and max in O(1) amortized:
        * minDeque: increasing values → front is min
        * maxDeque: decreasing values → front is max
    - As we increase i, add nums[i-1] to window, then increment left while (max-min) > k.
    - For valid window, any start j in [left..i-1] works → sum dp[j] = prefixSum over that range.
    - Use prefix sum pref[] to get that sum in O(1).
    - dp[0] = 1 (empty prefix), pref[0] = 1.
    - Answer = dp[n] modulo 1e9+7.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);  // pref[i] = dp[0] + ... + dp[i]

        dp[0] = 1;
        pref[0] = 1;

        deque<int> minD, maxD;  // store indices of elements for current window
        int left = 0;

        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            // Add nums[i-1] to window: update minD, maxD
            while (!minD.empty() && nums[minD.back()] > x) minD.pop_back();
            minD.push_back(i - 1);

            while (!maxD.empty() && nums[maxD.back()] < x) maxD.pop_back();
            maxD.push_back(i - 1);

            // Shrink window from left while invalid
            while (left < i) {
                int curMin = nums[minD.front()];
                int curMax = nums[maxD.front()];
                if (curMax - curMin <= k) break;

                // pop left index if it's at front
                if (!minD.empty() && minD.front() == left) minD.pop_front();
                if (!maxD.empty() && maxD.front() == left) maxD.pop_front();
                left++;
            }

            // Now window [left .. i-1] is valid
            // Any start j in [left .. i-1] gives valid segment ending at i-1
            // So dp[i] = sum(dp[j]) for j in [left .. i-1] => using prefix sum:
            if (left > 0) {
                dp[i] = (pref[i - 1] - pref[left - 1] + MOD) % MOD;
            } else {
                dp[i] = pref[i - 1];
            }

            pref[i] = (pref[i - 1] + dp[i]) % MOD;
        }

        return dp[n];
    }
};
