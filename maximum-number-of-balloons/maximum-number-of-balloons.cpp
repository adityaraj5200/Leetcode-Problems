class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = INT_MAX;
        map<char,int> freq;
        for(char &ch: text)
            freq[ch]++;
        
        set<char> characters = {'b','a','l','o','n'};
        for(char ch: characters){
            if(freq.find(ch) == freq.end()) return 0;
            ans = min(ans, (ch=='l'||ch=='o') ? freq[ch]/2 : freq[ch]);
        }
        
        return ans;
    }
};