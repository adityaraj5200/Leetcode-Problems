class Solution(object):
    def largestOddNumber(self, num):
        """
        :type num: str
        :rtype: str
        """
        ans = ""
        for i in reversed(range(len(num))):
            if (ord(num[i])-ord('0')) & 1:
                return num[:i+1]
        return ""