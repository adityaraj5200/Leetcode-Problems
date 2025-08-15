class Solution {
    public boolean isPowerOfFour(int n) {
        return (n>0) && (((n)&(n-1))==0) && (n-1)%3==0;
        // 1 - 1
        //2 - 10
        //4 - 100
        //8 - 10000

        // Number of 0s to the right side of set bit(1) is always even
        // 00
        // 0000
        // 000000

        // Convert those 0s into 1s and think of their value
        // 11 - 3
        // 1111 - 15
        // 111111 - 63
        // Always divisible by 3
    }
}