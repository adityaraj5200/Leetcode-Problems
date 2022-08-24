class Solution {
public:
    bool isPowerOfThree(int n) {
        int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > INT_MAX
        return n>0 && Max3PowerInt%n==0;
    }
};