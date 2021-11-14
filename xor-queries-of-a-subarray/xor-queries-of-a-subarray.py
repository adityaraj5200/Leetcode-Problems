class Solution(object):
    def xorQueries(self, arr, queries):
        """
        :type arr: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        dp = [None] * len(arr)
        xor = 0
        for i in range(len(arr)):
            xor ^= arr[i]
            dp[i] = xor
        
        ans = [None] * len(queries)
        for i in range(len(queries)):
            ans[i] = dp[queries[i][1]]^(dp[queries[i][0]-1] if queries[i][0]>0 else 0)
        
        return ans
        
        
        