class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length(), i=0;
        if(n<m) return {};
        vector<int> pFreq(26,0),sFreq(26,0);
        
        while(i<m){
            sFreq[s[i]-'a']++;
            pFreq[p[i]-'a']++;
            i++;
        }
        
        vector<int> ans;
        if(sFreq==pFreq) ans.push_back(i-m);
        
        while(i<n){
            sFreq[s[i-m]-'a']--;
            sFreq[s[i]-'a']++;
            if(sFreq==pFreq) 
                ans.push_back(i-m+1);
            i++;
        }
        return ans;
    }
};