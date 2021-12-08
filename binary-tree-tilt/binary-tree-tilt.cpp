/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        int leftsum = helper(root->left), rightsum = helper(root->right);
        ans += abs(leftsum-rightsum);
        return leftsum + rightsum + root->val;
    }
    
    int findTilt(TreeNode* root){
        helper(root);
        return ans;
    }
};