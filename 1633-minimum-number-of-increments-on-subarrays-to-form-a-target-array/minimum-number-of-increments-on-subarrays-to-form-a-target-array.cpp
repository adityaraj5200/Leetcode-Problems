// Time Complexity: O(n) where n = target.size()
// Space Complexity: O(1)

// Approach:
// • Treat the array as layers of increments: for each position, you only need extra operations when the current value exceeds the previous one.
// • Start with target[0] operations for the first element.
// • Then for each i from 1 to n-1, if target[i] > target[i–1], add (target[i] – target[i–1]) to the total operations.

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        if (n == 0) return 0;

        int operations = target[0];
        for (int i = 1; i < n; ++i) {
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }
        return operations;
    }
};
