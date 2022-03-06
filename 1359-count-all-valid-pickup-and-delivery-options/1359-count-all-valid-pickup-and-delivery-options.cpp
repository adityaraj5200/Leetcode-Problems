class Solution {
public:
    int countOrders(int n) {
        long long ans = 1, mod = 1e9+7;
        for(long long i=2;i<=n;i++)
            ans = (ans * (2*i-1) * i)%mod;
        
        return (int)ans;
    }
};