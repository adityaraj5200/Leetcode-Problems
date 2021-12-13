class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        parts,currsum,total = 0,0,sum(arr)
        if total%3 != 0:
            return False
        
        for item in arr:
            if parts==2:
                return True
            currsum += item
            if currsum == (parts+1)*(total/3):
                parts += 1
        
        return False