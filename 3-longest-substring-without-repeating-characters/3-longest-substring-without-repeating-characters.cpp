class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        
        int i=0,j=0,ans=0,n=s.length();
        while(i<n && j<n){
            while(i<n && st.find(s[i])==st.end()){
                st.insert(s[i++]);
                ans = max(ans,(int)st.size());
            }
            while(j<i && s[j]!=s[i]){
                st.erase(s[j++]);
            }
            st.erase(s[j++]);
        }
        
        return ans;
    }
};