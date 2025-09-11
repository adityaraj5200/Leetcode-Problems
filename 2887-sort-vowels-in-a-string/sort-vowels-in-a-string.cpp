// TC: O(n log n), SC: O(n)
class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        string collected;
        for(char c:s){
            if(vowels.count(c)) collected+=c;
        }
        sort(collected.begin(),collected.end());
        int k=0;
        for(char& c:s){
            if(vowels.count(c)) c=collected[k++];
        }
        return s;
    }
};
