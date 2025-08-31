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
class Solution {
    private int ans = 0;
    private int getDepth(TreeNode node){
        if(node == null) return 0;

        int leftDepth = getDepth(node.left);
        int rightDepth = getDepth(node.right);

        ans = Math.max(ans, 1 + leftDepth + rightDepth);

        return 1+Math.max(leftDepth,rightDepth);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        getDepth(root);
        return Math.max(0,ans-1);
    }
}