// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach:
// Use prefix sums where prefixSum = number of odd elements up to current index.
// For each index, if there exists a previous prefixSum = (current prefixSum - k),
// then the subarray between them has exactly k odd numbers.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), prefixSum = 0, ans = 0;
        vector<int> prefixCount(n + 1, 0);  // prefixSum → frequency count
        prefixCount[0] = 1;  // base case (empty subarray)
        

        for (int num : nums) {
            // Increment prefixSum if current number is odd
            if (num & 1) prefixSum++;

            // If there was a previous prefix with (prefixSum - k),
            // it means subarray between that prefix and current index has exactly k odds.
            if (prefixSum - k >= 0) {
                ans += prefixCount[prefixSum - k];
            }

            // Record current prefix sum
            prefixCount[prefixSum]++;
        }

        return ans;
    }
};
