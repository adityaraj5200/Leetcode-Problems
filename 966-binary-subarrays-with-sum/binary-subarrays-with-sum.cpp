// Time Complexity: O(n) where n = nums.size()
// Space Complexity: O(1) extra (or O(1) excluding input/output)
class Solution {
private:
    // Count subarrays with sum ≤ S
    int countAtMost(const vector<int>& nums, int S) {
        if (S < 0) return 0;
        int left = 0,count = 0, sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            // Shrink window until sum ≤ S
            while (sum > S) {
                sum -= nums[left];
                ++left;
            }
            // All subarrays ending at right with start in [left..right] are valid
            count += (right - left + 1);
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Number of subarrays with sum exactly = goal
        return (int)(countAtMost(nums, goal) - countAtMost(nums, goal - 1));
    }
};
