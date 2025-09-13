class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        int maxFreqVowel = 0;
        int maxFreqConsonant = 0;
        for(char& ch: s){
            bool isVowel = (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
            freq[ch-'a']++;

            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                maxFreqVowel = max(maxFreqVowel,freq[ch-'a']);
            }
            else{
                maxFreqConsonant = max(maxFreqConsonant,freq[ch-'a']);
            }
        }
        
        return maxFreqVowel+maxFreqConsonant;
    }
};