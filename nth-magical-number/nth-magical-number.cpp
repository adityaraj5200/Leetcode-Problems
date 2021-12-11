class Solution {
public:
    int nthMagicalNumber(int n, int a, int b){
        const int mod = 1e9+7;
        long long int low = min(a,b), high = n*low, N = n, lcm = a*b/__gcd(a,b);
        while(low < high){
            long long int mid = (low+high)/2;
            if(mid/a + mid/b - mid/lcm < N)
                low = mid+1;
            else high = mid;
        }
        return high%mod;
    }
};