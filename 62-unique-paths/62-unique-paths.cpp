class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1),temp(n,1);
        while(--m){
            temp[0] = 1;
            for(int i=1;i<n;i++)
                temp[i] = temp[i-1]+dp[i];
            dp.swap(temp);
        }
        return dp.back();
    }
};