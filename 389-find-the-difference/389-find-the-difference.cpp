class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = (int)t.back();
        for(int i=0,n=s.length();i<n;i++)
            res ^= (int)s[i] ^ (int)t[i];
        return (char)res;
    }
};