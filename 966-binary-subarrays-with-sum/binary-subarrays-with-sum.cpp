// Time Complexity: O(n)
// Space Complexity: O(n)
// Approach:
// Use prefix sum + hashmap to count subarrays whose sum equals `goal`.
// For each index, if prefixSum - goal has been seen before,
// it means there are that many subarrays ending here with sum = goal.

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), prefixSum = 0, result = 0;
        map<int,int> prefixCount;  // prefixSum → frequency
        prefixCount[0] = 1; // Base case: prefix sum = 0 occurs once


        for (int num : nums){
            prefixSum += num;

            // If there exists a prefix with sum = prefixSum - goal,
            // then subarray between that prefix and current index sums to `goal`.
            if (prefixCount.count(prefixSum - goal)) {
                result += prefixCount[prefixSum - goal];
            }

            // Record current prefixSum for future subarrays
            prefixCount[prefixSum]++;
        }

        return result;
    }
};
