/**
 * Approach:
 * 1. We want to find the level in the binary tree that has the maximum sum of node values.
 * 2. Use a Breadth-First Search (BFS) traversal to process the tree level by level.
 * 3. For each level:
 *    - Sum the values of all nodes in that level.
 *    - Compare with the current maximum sum.
 *    - If this level’s sum is greater than the recorded maximum, update the max sum and
 *      record this level index (1-indexed as required).
 * 4. Continue until all levels are processed.
 * 5. Return the level index with the highest sum. If multiple levels have the same sum,
 *    the earliest (smallest index) is kept because we only update on strictly greater sum.
 */

// Time & Space Complexity:
// Time Complexity: O(n)  Space Complexity: O(w) where w is the maximum width of the tree
class Solution {
    public int maxLevelSum(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        
        long maxSum = Long.MIN_VALUE;
        int resultLevel = 0;
        int currentLevel = 0;
        
        while (!queue.isEmpty()) {
            currentLevel++;
            int size = queue.size();
            long levelSum = 0;
            
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                levelSum += node.val;
                
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
            
            if (levelSum > maxSum) {
                maxSum = levelSum;
                resultLevel = currentLevel;
            }
        }
        
        return resultLevel;
    }
}
