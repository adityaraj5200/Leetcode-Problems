class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length(), m=needle.length(), len=0, i=1, j=0;
        if(m==0) return 0;;
        vector<int> lps(m,0);
        while(i<m){
            if(needle[i]==needle[len])
                lps[i++] = ++len;
            else{
                if(len) len = lps[len-1];
                else i++; 
            }
        }
        
        i = j = 0;
        while(i<n){
            if(haystack[i]==needle[j]) i++,j++;
            else {
                if(j!=0) j = lps[j-1];
                else i++;
            }
            if(j==m)
                return i-m;
        }
        
        return -1;
    }
};