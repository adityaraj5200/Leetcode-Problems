/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


/**
 * Approach:
 * 1. The product for splitting an edge is: (sum of one subtree) * (total sum - sum of that subtree).
 * 2. Compute the total sum of the tree with one DFS.
 * 3. Use a second DFS that returns subtree sums and for each node’s subtree compute
 *    the product of that subtree sum and (totalSum - subtreeSum).
 * 4. Track the maximum product seen.
 * 5. Return the maximum product modulo 1_000_000_007.
 */

// Time Complexity: O(n)  Space Complexity: O(h) where h is tree height
class Solution {
    private long totalSum;
    private long maxProduct;
    private static final long MOD = 1_000_000_007L;

    public int maxProduct(TreeNode root) {
        totalSum = total(root);
        maxProduct = 0;
        dfs(root);
        return (int)(maxProduct % MOD);
    }

    private long total(TreeNode node) {
        if (node == null) return 0;
        return node.val + total(node.left) + total(node.right);
    }

    private long dfs(TreeNode node) {
        if (node == null) return 0;
        long leftSum = dfs(node.left);
        long rightSum = dfs(node.right);
        long sub = node.val + leftSum + rightSum;
        long product = sub * (totalSum - sub);
        if (product > maxProduct) {
            maxProduct = product;
        }
        return sub;
    }
}
