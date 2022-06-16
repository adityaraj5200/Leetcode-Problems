class Solution {
public:
    string longestPalindrome(string s) {
        int bestLength = 0, n = s.length();
        string ans_str;
        for(int st=0;st<n;st++){
            int i=st,j=st,len=1;
            while(i>=0 && j<n && s[i]==s[j]){
                if(len > bestLength){
                    bestLength = len;
                    ans_str = s.substr(i,j-i+1);
                }
                i--;
                j++;
                len += 2;
            }
            
            i=st,j=st+1,len=2;
            
            while(i>=0 && j<n && s[i]==s[j]){
                if(len > bestLength){
                    bestLength = len;
                    ans_str = s.substr(i,j-i+1);
                }
                i--;
                j++;
                len += 2;
            }
        }
        
        return ans_str;
    }
};