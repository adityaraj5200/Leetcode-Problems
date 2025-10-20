// Time Complexity: O(n²) where n = s.length()
// Space Complexity: O(1) extra (since 26 letters only)
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int count[26] = {0};
            for (int j = i; j < n; ++j) {
                count[s[j] - 'a']++;
                int maxFreq = 0;
                int minFreq = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    if(count[k] > 0) {
                        maxFreq = max(maxFreq, count[k]);
                        minFreq = min(minFreq, count[k]);
                    }
                }
                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};
