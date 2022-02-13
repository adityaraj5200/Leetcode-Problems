class Solution {
public:    
    int minDistance(string word1, string word2) {
        const int n = word1.length(), m = word2.length();
        vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(m+1,0));
        int lcslength = 0; // it is the Longest Common Subsequence
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = word1[i-1]==word2[j-1] ? 1+dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]);
                lcslength = max(lcslength,dp[i][j]);
            }
        }

        return n+m - 2*lcslength;
    }
};