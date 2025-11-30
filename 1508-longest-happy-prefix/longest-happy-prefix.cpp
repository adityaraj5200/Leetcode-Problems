class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n,0);
        int i=1,lenMatched=0,maxLen=0,startPoint=-1;
        while(i<n){
            if(s[i]==s[lenMatched]){
                lps[i++] = ++lenMatched;
            }
            else{
                if(lenMatched>0) lenMatched = lps[lenMatched-1];
                else i++;
            }
        }

        return s.substr(0,lps[n-1]);
    }
};