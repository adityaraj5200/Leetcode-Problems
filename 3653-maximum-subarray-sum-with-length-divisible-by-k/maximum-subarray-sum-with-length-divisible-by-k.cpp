// Approach:
// - Let prefix[i] = sum of nums[0..i] (0-based).  
// - For a subarray nums[j+1 .. i] to have length divisible by k, we need (i - j) % k == 0 ⇒ i%k == j%k.  
// - So for current index i (with prefix sum = S), we want the minimum prefix sum previously seen at any index j where j%k == i%k.  
// - Maintain an array minPref of size k, where minPref[r] = minimum prefix sum among all indices j with j%k == r (or a sentinel for “before start”).  
// - Then candidate subarray sum = S - minPref[i%k]. Keep the max over all i.  
// - Update minPref[i%k] = min(minPref[i%k], S).  
// TC: O(n) — one scan over nums  
// SC: O(k) extra space (minPref array)

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 2;
        vector<long long> minPref(k, INF);
        // Sentinel: prefix sum 0 at “index = -1” whose mod class is (−1) % k = k−1
        minPref[(k - 1) % k] = 0;

        long long prefix = 0, ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int r = i % k;
            // Try subarray ending at i whose length is divisible by k
            ans = max(ans, prefix - minPref[r]);
            // Update minimum prefix sum seen so far for this remainder class
            minPref[r] = min(minPref[r], prefix);
        }
        return ans;
    }
};
