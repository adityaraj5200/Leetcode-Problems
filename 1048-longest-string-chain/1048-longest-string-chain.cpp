class Solution {
public:

    int longestStrChain(vector<string>& words){
        sort(words.begin(), words.end(),[](const string &s1, const string &s2) {
           return s1.length() < s2.length();
        });
        unordered_map<string, int> dp;
        
        int res = 0;
        
        for(string &word: words){
            dp[word] = 1;
            for(int j=0;j<word.length();j++){
                string possible_predecessor = word.substr(0,j)+word.substr(j+1);
                
                if(dp.find(possible_predecessor)!=dp.end())
                    dp[word] = max(dp[word],dp[possible_predecessor]+1);
            }
            res = max(res,dp[word]);
        }
        
        return res;
    }
};