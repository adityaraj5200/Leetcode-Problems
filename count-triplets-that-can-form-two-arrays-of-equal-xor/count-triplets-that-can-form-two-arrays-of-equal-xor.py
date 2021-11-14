class Solution(object):
    def countTriplets(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        ans = 0
        for i in range(n):
            xorval = 0
            for j in range(i,n):
                xorval ^= arr[j]
                if xorval == 0:
                    ans += j-i
        return ans