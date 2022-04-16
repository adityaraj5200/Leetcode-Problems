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
    int currsum = 0;
    
    void helper(TreeNode* root){
        if(root->right) helper(root->right);
        
        currsum += root->val;
        root->val = currsum;
        
        if(root->left) helper(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root!=NULL) helper(root);
        return root;
    }
};