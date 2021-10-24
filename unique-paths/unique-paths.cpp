class Solution {
public:
    int uniquePaths(int m, int n) {
//         int dp[m][n];
//         for(int i=0;i<m;i++) dp[i][0]=1;
//         for(int j=0;j<n;j++) dp[0][j]=1;
        
//         for(int i=1;i<m;i++)
//         for(int j=1;j<n;j++)
//         dp[i][j]=dp[i-1][j]+dp[i][j-1];
//         return dp[m-1][n-1];
        vector<int> dp(n,1),temp(n,1);
        while(--m){
            temp[0] = 1;
            for(int i=1;i<n;i++)
                temp[i] = temp[i-1]+dp[i];
            dp = temp;
        }
        return dp.back();
    }
};