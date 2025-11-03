// Time Complexity: O(n), where n = colors.length()
// Space Complexity: O(1)

// Approach:
// • Traverse the string `colors` looking for consecutive same‐color balloons.
// • For each group of same‐colored balloons, we must remove all but the one with the highest removal time.
// • Accumulate the cost: sum of that group’s neededTime values minus the maximum neededTime in that group.

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = 0;
        int maxTimeInGroup = neededTime[0];
        
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                // Still in the same color‐group: remove the cheaper one
                totalTime += min(maxTimeInGroup, neededTime[i]);
                // Keep the balloon with the highest cost to remove (so we can skip removing it)
                maxTimeInGroup = max(maxTimeInGroup, neededTime[i]);
            } else {
                // New color group starts
                maxTimeInGroup = neededTime[i];
            }
        }
        
        return totalTime;
    }
};
