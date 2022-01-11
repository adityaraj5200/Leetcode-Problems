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
    void helper(TreeNode* root,int currSum){
        currSum = (currSum<<1) + root->val;
        if(root->left) 
            helper(root->left,currSum);
        if(root->right) 
            helper(root->right,currSum);
        if(root->left==NULL && root->right==NULL)
            ans += currSum;
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root,0);
        return ans;
    }
};