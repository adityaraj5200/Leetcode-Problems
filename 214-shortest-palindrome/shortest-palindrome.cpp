/*
    Approach:
    - We want to find the longest prefix of s that is also a palindrome.
    - Reverse s to get rev_s.
    - Build a combined string: temp = s + '#' + rev_s. The '#' is a delimiter not in s.
    - Compute the KMP “prefix-function” (lps array) on temp.
      The value lps[last] gives the length of the longest prefix of s which matches a suffix of rev_s,
      which corresponds to the longest palindromic prefix of s.
    - Let L = lps[last]. Then the suffix s[L..end] is the part not included in that palindromic prefix.
      Reverse that suffix and prepend to s. That yields the shortest palindrome.
    - This works in O(n) time and O(n) space.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;

        int m = temp.size();
        vector<int> lps(m, 0);

        // build KMP prefix-function (lps)
        for (int i = 1; i < m; ++i) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                ++j;
            }
            lps[i] = j;
        }

        int L = lps[m - 1];  // length of longest palindromic prefix
        string suffix = s.substr(L);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};
