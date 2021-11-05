class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> exist(26,false);
        for(char &ch: allowed)
            exist[ch-'a'] = true;
        int ans = 0;
        for(string &s: words){
            bool add = true;
            for(char &ch: s){
                if(!exist[ch-'a']){
                    add = false;
                    break;
                }
            }
            ans += add;
        }
        return ans;
    }
};