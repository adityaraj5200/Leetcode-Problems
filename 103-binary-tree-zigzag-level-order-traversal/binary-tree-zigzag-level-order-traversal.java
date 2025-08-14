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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        
        if(root == null) return result;

        Stack<TreeNode> currLevelStk = new Stack<>();
        Stack<TreeNode> nextLevelStk = new Stack<>();
        currLevelStk.push(root);
        boolean leftToRight = true;
        List<Integer> currLevelArray = new ArrayList<>();

        while(!currLevelStk.isEmpty()){
            while(!currLevelStk.isEmpty()){
                TreeNode node = currLevelStk.pop();
                currLevelArray.add(node.val);

                if(leftToRight){
                    if(node.left != null) nextLevelStk.push(node.left);
                    if(node.right != null) nextLevelStk.push(node.right);
                }
                else{
                    if(node.right != null) nextLevelStk.push(node.right);
                    if(node.left != null) nextLevelStk.push(node.left);
                }
            }

            leftToRight = !leftToRight;

            result.add(new ArrayList<>(currLevelArray));
            currLevelArray.clear();
            
            Stack<TreeNode> temp = currLevelStk;
            currLevelStk = nextLevelStk;
            nextLevelStk = temp;
        }

        return result;
    }
}