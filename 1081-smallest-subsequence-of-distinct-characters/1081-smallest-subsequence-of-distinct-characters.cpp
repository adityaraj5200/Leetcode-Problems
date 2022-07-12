class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length(), last[26] = {};
        bool added[26] = {};
        
        for(int i=0;i<n;i++)
            last[s[i]-'a'] = i;
        
        string ans = "";
        
        for(int i=0;i<n;i++){
            if(added[s[i]-'a']) continue;
            
            while(!ans.empty() && ans.back()>s[i] && i<last[ans.back()-'a']){
                added[ans.back()-'a'] = false;
                ans.pop_back();
            }
            
            added[s[i]-'a'] = true;
            ans += s[i];
        }
        
        return ans;
    }
};