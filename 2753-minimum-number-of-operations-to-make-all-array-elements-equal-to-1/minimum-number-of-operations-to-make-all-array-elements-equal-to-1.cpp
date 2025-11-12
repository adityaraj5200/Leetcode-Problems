// TC: O(n^2 * log(max_element))
// SC: O(1)
// Approach:
// - Count how many elements are already 1; if >0, we can convert the rest individually in (n-ones) operations.
// - If no element is 1, find the shortest subarray whose gcd = 1. For any such subarray of length L, it takes (L-1) operations to make that subarray all 1s (by repeatedly replacing subarray gcd).
//   After that, the rest (n − 1) elements each require one operation to become 1.
// - So total = (L-1) + (n-1) = L + n − 2.
// - If no such subarray exists, return -1.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int countOnes = count(nums.begin(), nums.end(), 1);
        if (countOnes > 0) {
            return n - countOnes;
        }
        int minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        if (minLen == INT_MAX) {
            return -1;
        }
        return (minLen - 1) + (n - 1);
    }
};
