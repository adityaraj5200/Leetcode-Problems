class Solution:
    def longestPalindrome(self, s: str) -> int:
        Dict = {}
        for item in s:
            if item in Dict:
                Dict[item] += 1
            else:                
                Dict[item] = 1
        
        # print(Dict)
        
        oddLenEle,ans = False,0
        for key,value in Dict.items():
            # print(key)
            if value & 1:
                value -= 1
                oddLenEle = True
            ans += value
        
        if oddLenEle:
            ans += 1
        
        return ans