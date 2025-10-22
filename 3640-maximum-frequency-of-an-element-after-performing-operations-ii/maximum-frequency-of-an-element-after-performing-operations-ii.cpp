// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Approach:
// 1. Sort the array for binary search operations.
// 2. For each element, check how many nearby elements can be converted
//    to this value (or within k range) using up to 'numOperations' operations.
// 3. Return the highest possible frequency after allowed operations.

class Solution {
public:
    // Helper function to calculate max frequency achievable for a target value
    int calculateFrequency(const vector<int>& nums, long long target, long long range, int numOperations) {
        // Indices where nums == target
        int equalStart = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int equalEnd = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        // Indices for numbers within [target - range, target + range]
        int rangeStart = lower_bound(nums.begin(), nums.end(), target - range) - nums.begin();
        int rangeEnd = upper_bound(nums.begin(), nums.end(), target + range) - nums.begin();

        // Count of numbers that can be converted to 'target'
        int convertibleCount = (rangeEnd - equalEnd) + (equalStart - rangeStart);

        // Add up to 'numOperations' of these convertible numbers to the base count
        return min(numOperations, convertibleCount) + (equalEnd - equalStart);
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int maxFreq = 1;

        for (int i = 0; i < nums.size(); i++) {
            long long val = nums[i];
            long long range = k;

            // Check three possible targetValue ranges:
            maxFreq = max(maxFreq, calculateFrequency(nums, val, range, numOperations));
            maxFreq = max(maxFreq, calculateFrequency(nums, val - range, range, numOperations));
            maxFreq = max(maxFreq, calculateFrequency(nums, val + range, range, numOperations));
        }

        return maxFreq;
    }
};
