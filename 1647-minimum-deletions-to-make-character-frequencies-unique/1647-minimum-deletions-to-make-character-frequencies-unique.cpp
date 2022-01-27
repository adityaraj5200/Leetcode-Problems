class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char &ch: s)
            freq[ch-'a']++;
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int ans = 0;
        for(int i=1;i<26;i++){
            if(freq[i] >= freq[i-1]){
                int del = freq[i]-freq[i-1] + (freq[i-1]!=0);
                freq[i] -= del;
                ans += del;
            }
        }
        
        return ans;
    }
};