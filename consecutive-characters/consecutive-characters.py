class Solution:
    def maxPower(self, s: str) -> int:
        prev = '.'
        currlen,maxlen = 0,1
        for ch in s:
            if ch == prev:
                currlen += 1
                maxlen = max(maxlen,currlen)
            else:
                currlen = 1
            prev = ch
        return maxlen