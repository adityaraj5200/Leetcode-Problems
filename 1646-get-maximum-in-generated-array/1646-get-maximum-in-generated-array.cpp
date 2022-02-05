class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> ans(n+1,0);
        if(n>0) ans[1] = 1;
        for(int i=0;i<=n;i++){
            if(2*i <= n) ans[2*i] = max(ans[2*i], ans[i]);
            if(2*i+1 <= n) ans[2*i+1] = max(ans[2*i+1],ans[i]+ans[i+1]);
        }
        return *max_element(ans.begin(),ans.end());
    }
};