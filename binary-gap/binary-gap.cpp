class Solution {
public:
    int binaryGap(int n) {
        if((n&(n-1))==0) return 0;
        int cnt = -100, ans = 0;
        while(n){
            if(n&1) cnt = 1;
            else cnt++;
            ans = max(cnt,ans);
            n >>= 1;
        }
        return ans;
    }
};