// Time Complexity: O(log n)
// Space Complexity: O(1)

// Approach:
// • Recognize that numbers with binary representation of all 1’s are of the form 2^k−1 (e.g., 1, 3, 7, 15, ...).
// • Find the smallest power-of-two x such that x−1 ≥ n.
// • Return x−1, which has all bits set and is the smallest such number ≥ n.

class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while (x - 1 < n) {
            x <<= 1; // move to next power of two
        }
        return x - 1;
    }
};
