class Solution(object):
    def numSplits(self, s):
        """
        :type s: str
        :rtype: int
        """
        rightmap = Counter(s)
        leftmap = defaultdict(int)
        ans = 0
        
        for ch in s:
            rightmap[ch] -= 1
            if rightmap[ch] == 0:
                del rightmap[ch]
            leftmap[ch] += 1
            
            if len(leftmap) == len(rightmap):
                ans += 1
        
        return ans
        