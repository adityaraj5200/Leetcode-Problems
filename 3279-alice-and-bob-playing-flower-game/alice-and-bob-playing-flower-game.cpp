class Solution {
public:
    long long flowerGame(int n, int m) {
        long long totalWays = 0;
        long long oddn=n/2+n%2;
        long long evenn=n/2;
        long long oddm=m/2+m%2;
        long long evenm=m/2;

        totalWays += oddn*evenm;
        totalWays += evenn*oddm;

        return totalWays;
    }
};