class Solution {
public:
    long long flowerGame(int n, int m) {
        long long totalWays = 0;
        long long oddn=(((n&1)?n:n-1)+1)/2;
        long long evenn=((n&1)?n-1:n)/2;
        long long oddm=(((m&1)?m:m-1)+1)/2;
        long long evenm=((m&1)?m-1:m)/2;

        totalWays += oddn*evenm;
        totalWays += evenn*oddm;

        return totalWays;
    }
};