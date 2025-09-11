class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowelsIndices;
        string vowelsOfStr;
        set<int> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<s.length();i++){
            if(vowels.find(s[i]) != vowels.end()){
                vowelsOfStr += s[i];
            }
        }

        sort(vowelsOfStr.begin(), vowelsOfStr.end());
        for(int i=0,k=0;i<s.length();i++){
            if(vowels.find(s[i]) != vowels.end()){
                s[i] = vowelsOfStr[k++];
            }
        }

        return s;
    }
};