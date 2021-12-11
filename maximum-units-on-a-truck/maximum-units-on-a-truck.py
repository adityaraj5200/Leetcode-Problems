class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        """
        :type boxTypes: List[List[int]]
        :type truckSize: int
        :rtype: int
        """
        def customsort(a,b):
            if a[1] > b[1]:
                return -1
            elif a[1] == b[1]:
                if a[0] > b[0]:
                    return 1
                else:
                    return -1
            else:
                return 1
        
        boxTypes.sort(customsort)
        print(boxTypes)
        ans = 0
        for box in boxTypes:
            if truckSize - box[0] >= 0:
                ans += box[0]*box[1]
                truckSize -= box[0]
            else:
                ans += truckSize*box[1]
                break
        return ans
        