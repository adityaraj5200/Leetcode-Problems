class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n = s1.length(), m = s2.length();
        if(n > m) return false;        
        vector<int> freqs1(26,0);
        vector<int> freqs2(26,0);
        
        for(int i=0;i<n;i++){
            freqs1[s1[i]-'a']++;
            freqs2[s2[i]-'a']++;
        }
        
        int notmatch = 0;
        for(int i=0;i<26;i++)
            if(freqs1[i] != freqs2[i])
                notmatch++;
        
        if(notmatch==0) return true;
        
        for(int i=n;i<m;i++){
            if(freqs2[s2[i]-'a'] == freqs1[s2[i]-'a']) notmatch++;
            freqs2[s2[i]-'a']++;
            if(freqs2[s2[i]-'a'] == freqs1[s2[i]-'a']) notmatch--;
            
            if(freqs2[s2[i-n]-'a'] == freqs1[s2[i-n]-'a']) notmatch++;
            freqs2[s2[i-n]-'a']--;
            if(freqs2[s2[i-n]-'a'] == freqs1[s2[i-n]-'a']) notmatch--;
            
            if(notmatch==0)
                return true;
        }
        
        return false;
    }
};