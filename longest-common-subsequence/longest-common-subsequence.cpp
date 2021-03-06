class Solution {
public:
    vector<vector<int>> dp;

    int helper(string& A,string& B,int n,int m){
        if(n<0 || m<0) return 0;
        if(dp[n][m]) return dp[n][m];
        if(A[n]==B[m]) return (1 + helper(A,B,n-1,m-1));
        return dp[n][m]=max(helper(A,B,n-1,m),helper(A,B,n,m-1));
    }
    
    int longestCommonSubsequence(string A, string B) {
        int n=A.length(),m=B.length();
        dp.resize(n);
        for(int i=0;i<n;i++)
        dp[i].resize(m,0);
        
        return helper(A,B,n-1,m-1);
    }
};