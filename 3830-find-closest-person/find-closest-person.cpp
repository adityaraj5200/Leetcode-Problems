class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff = abs(x-z)-abs(y-z);
        if(diff>0) return 2;
        if(diff<0) return 1;
        return 0;
    }
};