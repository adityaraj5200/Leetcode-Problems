class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = n;
        while(temp){
            if((temp&1) != (n&1)) return false;
            temp >>= 2;
        }
        if((n&1) == ((n>>1)&1)) return false;
        temp = n >>= 1;
        while(temp){
            if((temp&1) != (n&1)) return false;
            temp >>= 2;
        }
        return true;
    }
};