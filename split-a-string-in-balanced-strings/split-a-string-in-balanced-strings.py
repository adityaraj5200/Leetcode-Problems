class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt,l,r = 0,0,0
        for i in range(len(s)):
            if s[i] == 'L':
                l += 1
            else:
                r += 1
                
            if l==r:
                cnt += 1
        return cnt