class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int left = 0, zeroCount = 0, oneCount = 0, maxLen = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeroCount++;
            } else {
                oneCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                } else {
                    oneCount--;
                }
                left++;
            }

            maxLen = Math.max(maxLen, oneCount - (zeroCount>0 ? 0 : 1));
        }

        return maxLen;
    }
}