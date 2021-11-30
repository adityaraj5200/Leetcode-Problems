class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = n ? matrix[0].size() : 0, ans = 0;
        if(n==0 || m==0) return 0;
        vector<int> dp(m,0);
        for(int i=0;i<n;i++){   
            for(int j=0;j<m;j++)
                dp[j] = matrix[i][j] == '1' ? dp[j]+1 : 0;
            ans = max(ans, largestRectangle(dp));
        }
        
        return ans;
    }
    
    int largestRectangle(vector<int>& height){
        int n = height.size();
        stack<int> stk1,stk2;
        vector<int> nsr(n),nsl(n);
        for(int i=n-1,j=0;i>=0;i--,j++){
            while(!stk1.empty() && height[stk1.top()]>=height[i])
                stk1.pop();
            nsr[i] = !stk1.empty() ? stk1.top() : n;
            stk1.push(i);
            
            while(!stk2.empty() && height[stk2.top()]>=height[j])
                stk2.pop();
            nsl[j] = !stk2.empty() ? stk2.top() : -1;
            stk2.push(j);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans, height[i]*(nsr[i]-nsl[i]-1));
        return ans;
    }
};