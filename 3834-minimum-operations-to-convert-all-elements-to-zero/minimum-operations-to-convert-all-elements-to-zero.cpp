// TC: O(n)
// SC: O(n)
//
// Approach:
// - Use a monotonic increasing stack to keep track of "active" heights (numbers).
// - Each time we encounter a number greater than the top, we start a new operation.
// - Each time we encounter a number smaller than the top, we pop until the top ≤ current number.
// - Equal values mean continuation of same segment (no new operation).
//
// Example walkthrough at bottom.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;      // will store increasing numbers
        st.push(0);         // sentinel base value (acts like ground level)
        int operations = 0; // final answer

        for (int num : nums) {
            // Step 1: If current number is smaller, pop larger elements
            while (!st.empty() && st.top() > num) {
                st.pop(); // previous higher segment ends here
            }

            // Step 2: If current number starts a new segment (greater than top)
            if (st.top() < num) {
                operations++; // new non-zero segment => new operation
                st.push(num);
            }

            // Step 3: If st.top() == num, it's part of same height block, do nothing
        }

        return operations;
    }
};
