class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0) return true;
        if(s.length() > t.length()) return false;
        
        for(int i=0,j=0;i<t.length();i++){
            if(t[i]==s[j]){
                j++;
                if(j==s.length()) 
                    return true;
            }
        }
        return false;
    }
};