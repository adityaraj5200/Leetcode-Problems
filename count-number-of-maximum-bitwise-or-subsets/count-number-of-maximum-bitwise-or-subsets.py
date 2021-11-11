class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxOR = cnt = 0
        for item in nums:
            maxOR |= item
        for currmask in range(1,1<<len(nums)):
            i = currOR = 0
            while currmask>0:
                if currmask%2 == 1:
                    currOR |= nums[i]
                    if currOR == maxOR:
                        cnt += 1
                        break
                i += 1
                currmask >>= 1
        return cnt
        