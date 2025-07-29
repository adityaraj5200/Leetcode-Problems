class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n = nums.size(), offset = n;
		vector<int> seenSumAt(n+1+offset, INT_MIN);
		seenSumAt[offset] = -1; // This is like saying that we saw sum (0+offset) at index -1
        int maxLen = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 0 ? -1 : 1);
			if (seenSumAt[sum + offset] != INT_MIN){ // We have seen this sum before, which means we can create a subarray from where it was seen first and the current index
                maxLen = max(maxLen, i - seenSumAt[sum + offset]);
            }
			else seenSumAt[sum + offset] = i; // havn't seen. Mark it and remember it for future
        }
        return maxLen;
    }
};