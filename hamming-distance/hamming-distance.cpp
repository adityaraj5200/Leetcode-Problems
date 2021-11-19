class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0, val = x^y;
        while(val){
            val &= val-1;
            count++;
        }
        return count;
    }
};