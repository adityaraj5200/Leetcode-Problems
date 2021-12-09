class Solution(object):
    def diStringMatch(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        myList = []
        upper = len(s)
        lower = 0
        
        for ch in s:
            if ch == 'I':
                myList.append(lower)
                lower += 1
            else:
                myList.append(upper)
                upper -= 1
                
        myList.append(lower)
        return myList   