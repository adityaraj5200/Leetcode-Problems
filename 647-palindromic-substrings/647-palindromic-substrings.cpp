class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        
        for(int i=0;i<n;i++){
            int st=i, end=i;
            while(st>=0 && end<n && s[st]==s[end]){
                ans++, st--, end++;
            }
            
            st=i, end=i+1;
            while(st>=0 && end<n && s[st]==s[end]){
                ans++, st--, end++;
            }
        }
        
        return ans;
    }
};