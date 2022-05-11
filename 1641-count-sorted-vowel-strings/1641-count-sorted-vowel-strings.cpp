class Solution {
public:
    int countVowelStrings(int n) {
        // vector<char> characters = {'a','e','o','u','i'};
        // int dp[n][5];
        vector<int> dp(5,1);
        for(int i=0;i<n;i++){
            for(int j=3;j>=0;j--){
                dp[j] += dp[j+1];
            }
        }
        return dp[0];
    }
};