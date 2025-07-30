class Solution {
    typedef long long ll;
public:
        int nthUglyNumber(int n, int a, int b, int c) {
        ll l=1, r=2e9, ans=0;
        ll lcmab=lcm(a,b), lcmbc=lcm(b,c), lcmac=lcm(a,c);
        ll abc=lcm(lcmab,c);
        
        // How many unique numbers are divisible by either a,b or c between the range [l,r]
        while(l<=r){
            ll mid=(l+r)/2;
            ll cnt=mid/a + mid/b + mid/c - mid/lcmab - mid/lcmbc - mid/lcmac + mid/abc;
            
            if(cnt<n){
                l=mid+1;
            } else {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
private:

    ll gcd(ll a, ll b) {
        while(b){
            ll temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return (a/gcd(a,b))*b;
    }
};
