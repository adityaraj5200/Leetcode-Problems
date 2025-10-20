class Solution {
public:
    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;  // ceil(n/2)
        long long primePositions = n / 2;       // floor(n/2)

        long long part1 = modPow(5, evenPositions);
        long long part2 = modPow(4, primePositions);

        return (part1 * part2) % MOD;
    }

private:
    const int MOD = 1e9+7;
    long long modPow(long long x,long long n){
        if(n==0) return 1;

        long long half=modPow(x,n/2)%MOD;
        long long res=(half*half)%MOD;
        if(n&1) res=(res*(x%MOD))%MOD;
        return res;
    }

};
