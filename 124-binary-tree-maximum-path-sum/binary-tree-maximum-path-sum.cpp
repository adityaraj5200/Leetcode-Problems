// Approach:
// 1. Perform a postorder DFS traversal to compute max path sum at each node.
// 2. For each node:
//      - Compute the maximum sum path from its left and right child (ignore negatives using max(0, ...)).
//      - Update the global answer `maxSum` as the maximum of its current value and the path passing through this node (node->val + left + right).
//      - Return the maximum single-branch path (node->val + max(left, right)) to parent.
// 3. Finally, return the maximum path sum found.
//
// Time Complexity: O(n) — visit each node once
// Space Complexity: O(h) — recursion stack, where h is tree height

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        int left = max(0, dfs(node->left, maxSum));
        int right = max(0, dfs(node->right, maxSum));

        // Path through current node
        maxSum = max(maxSum, node->val + left + right);

        // Return max gain if we continue the path upward
        return node->val + max(left, right);
    }
};
