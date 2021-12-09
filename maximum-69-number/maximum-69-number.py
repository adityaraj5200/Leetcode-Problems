class Solution(object):
    def maximum69Number (self, num):
        """
        :type num: int
        :rtype: int
        """
        currPos,flipPos,tempnum = 0,-1,num
        while tempnum>0:
            if tempnum % 10 == 6:
                flipPos = currPos
            currPos += 1
            tempnum /= 10
        
        if flipPos != -1:
            num += 3 * (10**flipPos)
        
        return num
        