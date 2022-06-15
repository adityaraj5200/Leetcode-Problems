class Solution {
public:
    map<int,set<string>> m;
    map<string,int> dp;
    
    
    int longestStrChain(vector<string>& words) {
        for(string &word: words){
            m[word.length()].insert(word);
            dp[word] = 1;
        }
        
        int ans = 1;
        for(int len=2;len<=16;len++){
            for(string word: m[len]){
                for(int skip=0;skip<len;skip++){
                    string possible_predecessor;
                    for(int i=0;i<len;i++){
                        if(i==skip) continue;
                        possible_predecessor += word[i];
                        
                    }
                    if(m[len-1].find(possible_predecessor) != m[len-1].end()){
                        dp[word] = max(dp[word], 1+dp[possible_predecessor]);
                        ans = max(ans, dp[word]);
                    }
                }
            }
        }
        
        return ans;
        
    }
};