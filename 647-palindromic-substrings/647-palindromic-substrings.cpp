class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
            dp[i][i] = true;
        
        for(int i=0;i<n;i++){
            int st=i-1, end=i+1;
            while(st>=0 && end<n && s[st]==s[end]){
                dp[st--][end++] = true;
            }
            
            st=i, end=i+1;
            while(st>=0 && end<n){
                if(s[st] == s[end])
                    dp[st][end] = true;
                else break;
                st--, end++;
            }
        }
        
        int ans = 0;
        for(auto &vec: dp)
            for(bool value: vec)
                ans += value==true ? 1 : 0;
        
        return ans;
    }
};