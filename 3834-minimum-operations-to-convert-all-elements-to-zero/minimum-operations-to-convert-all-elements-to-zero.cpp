// TC: O(n log n)
// SC: O(n)
//
// Approach:
// 1. Group all indices of each distinct value in the array.
// 2. Keep a set `zeroIndices` to represent barriers (where nums[i] == 0).
//    We also insert `n` as a sentinel "wall" beyond array end.
// 3. Iterate over values in increasing order (smallest first).
//    - For each index having that value:
//        • If it's not blocked by a previous wall (i.e., index > nextWall),
//          we start a new operation.
//        • We then find the next wall position using `upper_bound()`
//          and mark this index as a new wall (zero-like position).
// 4. The number of times we start a new operation = answer.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        // Step 1: Group indices by value
        map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                valueToIndices[nums[i]].push_back(i);
            }
        }

        // Step 2: Maintain set of "zero" indices (walls/barriers)
        set<int> zeroIndices;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) zeroIndices.insert(i);
        }
        zeroIndices.insert(n); // sentinel wall

        // Step 3: Process values in increasing order
        for (auto& [value, indices] : valueToIndices) {
            int nextWall = -1; // last barrier we hit
            for (int index : indices) {
                if (index > nextWall) {
                    // Starting a new operation
                    operations++;

                    // Next wall is first zero after this index
                    nextWall = *zeroIndices.upper_bound(index);
                }

                // Mark this position as "zeroed out" (becomes new barrier)
                zeroIndices.insert(index);
            }
        }

        return operations;
    }
};
