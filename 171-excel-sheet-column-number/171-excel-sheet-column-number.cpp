class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int ans = 0;
        reverse(columnTitle.begin(),columnTitle.end());
        long long int multiplier = 1;
        for(char &ch: columnTitle){
            ans += (ch-'A'+1)*multiplier;
            multiplier *= 26;
        }
        return ans;
    }
};