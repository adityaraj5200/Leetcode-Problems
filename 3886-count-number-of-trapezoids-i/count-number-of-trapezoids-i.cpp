/*
    Approach:
    - A horizontal trapezoid is formed by choosing:
        * 2 points from one horizontal line (same y)
        * 2 points from another different horizontal line
    - So for each distinct y-coordinate:
        Let cnt[y] = number of points on that horizontal line.
        Number of ways to choose a base from that line = C(cnt[y], 2).
    - If we compute basePairs[y] = C(cnt[y], 2), then:
        The answer is the sum of basePairs[i] * basePairs[j] for all distinct i < j.
    - To compute this efficiently:
        * Keep a running sum of basePairs seen so far.
        * For each new basePairs value:
              ans += basePairs * runningSum
              runningSum += basePairs
    - This counts all valid unordered pairs of horizontal lines exactly once.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> freq;

        // Count how many points lie on each y-coordinate
        for (auto &p : points) {
            freq[p[1]]++;
        }

        long long ans = 0;
        long long runningSum = 0;
        const long long mod = 1LL*(1e9+7);

        // For each y-level, compute C(cnt, 2) and combine with previous levels
        for (auto &it : freq) {
            long long cnt = it.second;

            // If just 1 point, cannot form a horizontal base
            if (cnt==1) continue;

            long long basePairs = (cnt * (cnt - 1)) / 2;

            // Pair current base choices with all previous base choices
            ans = (ans + (basePairs * runningSum))%mod;

            // Add current base choices to running total
            runningSum += basePairs;
        }

        return ans;
    }
};
