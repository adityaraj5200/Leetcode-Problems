// Time Complexity: O(n) where n = nums.size()
// Space Complexity: O(1)

// Approach:
// • Compute the difference array: diff[i] = target[i] − nums[i].
// • Iterate through the array of differences one by one.
// • If the sign remains the same as the previous difference, add only the positive increase in absolute value.
// • If the sign changes (or becomes 0 from non-0, or vice versa), add the full absolute value of the new difference.
// • The sum of these increments is the minimum number of operations needed.

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long operations = llabs((long long)target[0] - nums[0]);

        for (int i = 1; i < n; ++i) {
            long long currDiff = (long long)target[i] - nums[i];
            long long prevDiff = (long long)target[i - 1] - nums[i - 1];

            // same sign and non-zero: reuse previous operations partially
            if ((currDiff >= 0 && prevDiff >= 0) || (currDiff <= 0 && prevDiff <= 0)) {
                long long heightJump = llabs(currDiff) - llabs(prevDiff);
                if (heightJump > 0){
                    operations += heightJump;
                }
            } else {
                // sign changed: need full operations for this position
                operations += llabs(currDiff);
            }
        }

        return operations;
    }
};
