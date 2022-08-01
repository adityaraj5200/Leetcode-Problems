class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int n = s.length();
        vector<bool> added(26,false);
        vector<int> last(26,-1);
        
        for(int i=0;i<n;i++){
            last[s[i]-'a'] = i;
        }
        
        string ans = "";
        for(int i=0;i<n;i++){
            if(added[s[i]-'a']) 
                continue;
            
            while(ans.length()>0 && ans.back()>s[i] && last[ans.back()-'a']>i){
                added[ans.back()-'a'] = false;
                ans.pop_back();
            }
            
            ans += s[i];
            added[s[i]-'a'] = true;
        }
        
        return ans;
    }
};