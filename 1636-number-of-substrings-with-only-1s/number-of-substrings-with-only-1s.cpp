// TC: O(n)
// SC: O(1)
// Approach:
// Maintain length of current consecutive '1's streak. 
// Every time you extend the streak, add its length to answer. 
// Reset streak when '0' appears. Use modulo as required.

class Solution {
public:
    int numSub(string s) {
        const int MOD=1e9+7;
        long long ans=0,streak=0;

        for(char c:s){
            streak = c=='1'?streak+1:0;
            ans = (ans+streak)%MOD;
        }
        return ans;
    }
};
