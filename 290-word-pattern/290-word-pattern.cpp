class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> mp;
        map<string,char> mp2;
        int i=0,j=0, n=pattern.length(), m=s.length();
        while(i<n){
            string word;
            while(j<m && s[j]!=' ')
                word += s[j++];
            j++;
            
            if(mp.find(pattern[i]) == mp.end())
                mp[pattern[i]] = word;
            else if(mp[pattern[i]] != word)
                return false;
            
            if(mp2.find(word) == mp2.end())
                mp2[word] = pattern[i];
            else if(mp2[word] != pattern[i])
                return false;
            
            i++;
        }
        j--;
        return j==m;
    }
};