class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.length(), ans=0;
        for(int i=1;i<n-1;i++){
            set<char> st = {s[i],s[i-1],s[i+1]};
            if(st.size()==3)
                ans++;
        }
        return ans;
    }
};