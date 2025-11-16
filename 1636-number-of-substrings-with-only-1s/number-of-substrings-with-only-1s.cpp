class Solution {
public:
    int numSub(string s) {
        int ans = 0, continuousOnes = 0, MOD = 1e9+7;

        for(char& ch: s){
            continuousOnes = ch=='1' ? continuousOnes+1 : 0;
            ans = (ans+continuousOnes)%MOD;
        }

        return ans;
    }
};