/*
    Approach:
    - Let totalSum = sum of all elements in nums. Let rem = totalSum % p.
    - If rem == 0: the totalSum sum is already divisible by p → no need to remove anything → return 0.
    - Otherwise, we need to remove a contiguous subarray whose sum % p == rem. Because:
         (totalSum - subarray_sum) % p == 0  →  subarray_sum % p == rem.
    - Use prefix sums modulo p: as we iterate, maintain prefixSumMod = (sum of nums[0..i]) % p.
      We also store in a hash map the last index where each prefixSumMod value occurred.
    - At index i with prefixSumMod = cur:
         we want a previous prefixSumMod = target = (cur - rem + p) % p.
         If we find such a previous index j, then removing subarray nums[j+1..i] works.
         Update answer as min length i - j.
    - Use the hash map to get this in O(1) average time, in a single pass. This yields overall O(n) time.
    - If we never find such subarray (other than removing whole array), return -1.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = accumulate(nums.begin(),nums.end(),0LL);
        long long rem = totalSum % p;
        if (rem == 0LL) return 0;

        int n = nums.size();
        map<long long, int> lastIndex;
        lastIndex[0] = -1;  // prefixSumMod = 0 at virtual index -1

        int ans = n;
        long long prefixSumMod = 0;
        for (int i = 0; i < n; ++i) {
            prefixSumMod = (prefixSumMod + 1LL*nums[i]) % p;
            long long target = (prefixSumMod - rem + p) % p;
            if (lastIndex.find(target) != lastIndex.end()) {
                ans = min(ans, i-lastIndex[target]);
            }
            // update last seen index of this prefixSumMod
            lastIndex[prefixSumMod] = i;
        }

        return (ans == n ? -1 : ans);
    }
};
