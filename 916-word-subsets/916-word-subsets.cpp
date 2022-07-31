class Solution {
public:
    vector<int> getFreq(string &s){
        vector<int> freq(26,0);
        for(char &ch: s)
            freq[ch-'a']++;        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26,0);
        for(string &b: words2){
            vector<int> freq = getFreq(b);
            for(int i=0;i<26;i++){
                maxFreq[i] = max(maxFreq[i],freq[i]);
            }
        }
        
        vector<string> ans;
        for(string &a: words1){
            vector<int> freq = getFreq(a);
            bool consider = true;
            for(int i=0;i<26;i++){
                if(maxFreq[i] > freq[i]){
                    consider = false;
                    break;
                }
            }
            
            if(consider){
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};