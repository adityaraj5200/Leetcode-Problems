class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        Dict = {5:0,10:0,20:0};
        for item in bills:
            Dict[item] += 1
            if item == 10:
                if Dict[5]>0:
                    Dict[5] -= 1
                else:
                    return False
            elif item == 20:
                if Dict[10]>=1 and Dict[5]>=1:
                    Dict[10] -= 1
                    Dict[5] -= 1
                elif Dict[5]>=3:
                    Dict[5] -= 3
                else:
                    return False
        return True