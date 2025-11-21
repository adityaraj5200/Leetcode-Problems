class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, n = s.length();
        vector<int> first(26,n), last(26,-1);

        for(int i=0,j=n-1;i<n;i++,j--){
            first[s[j]-'a'] = j;
            last[s[i]-'a'] = i;
        }

        for(int charNum=0;charNum<26;charNum++){
            int f = first[charNum];
            int l = last[charNum];

            set<int> unique;
            for(int i=f+1;i<l;i++){
                unique.insert(s[i]);
            }
            ans += unique.size();
        }

        return ans;
    }
};