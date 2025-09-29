class Solution {
public:
    int dp[50][50],n;
    
    int helper(vector<int>& values,int i,int j){
        if(i==j-1) return 0;
        if(dp[i][j]) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans,values[i]*values[j]*values[k] + helper(values,i,k)+helper(values,k,j));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        n=values.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = 0;
        
        return helper(values,0,n-1);
    }
};