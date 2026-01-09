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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        TreeNode leftMost = root;
        TreeNode rightMost = root;

        Queue<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        while(!q.isEmpty()){
            int size = q.size();
            leftMost = q.peek();
            for(int t=0;t<size;t++){
                TreeNode node = q.poll();
                if(node.left != null){
                    q.add(node.left);
                }
                if(node.right != null){
                    q.add(node.right);
                }
                
                rightMost = node;
            }
        }

        TreeNode ans = LCA(root, leftMost, rightMost);
        return ans;
    }

    private TreeNode LCA(TreeNode node, TreeNode p, TreeNode q){
        if(node==null || node==p || node==q){
            return node;
        }

        TreeNode leftSide = LCA(node.left, p, q);
        TreeNode rightSide = LCA(node.right, p, q);

        if(leftSide == null){
            return rightSide;
        }
        if(rightSide == null){
            return leftSide;
        }

        return node;
    }
}