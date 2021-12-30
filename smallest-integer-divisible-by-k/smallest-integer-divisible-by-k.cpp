class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) 
            return -1;
        
        for(int remainder = 1%k, length = 1; true ; length++){
            if(remainder == 0)
                return length;
            remainder = (remainder*10+1)%k;
        }
        
        return 1;
    }
};