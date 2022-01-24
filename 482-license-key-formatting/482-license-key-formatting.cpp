class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        reverse(s.begin(),s.end());
        string result;
        int charAdded = 0;
        for(char &ch: s){
            if(ch == '-') continue;
            
            result += toupper(ch);
            charAdded++;
            if(charAdded % k == 0)
                result += '-';
        }
        if(result.back()=='-')
            result.pop_back();
        reverse(result.begin(),result.end());
        return result;
    }
};