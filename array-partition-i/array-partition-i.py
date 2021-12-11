class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        ans,i,n = 0,0,len(nums)
        while i<n:
            ans += nums[i]
            i += 2
        return ans