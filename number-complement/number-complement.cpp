class Solution {
public:
    int findComplement(int num) {
        unsigned mask = 1;
        while(mask <= num)
            mask <<= 1;
        return (mask-1) ^ num;
    }
};