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
    int getDepth(TreeNode* root,int &ans){
        if(root == NULL) return 0;
        
        int left = 1 + getDepth(root->left,ans);
        int right = 1 + getDepth(root->right,ans);
        
        ans = max(ans,left+right-1);
        
        return max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getDepth(root,ans);
        return ans-1;
    }
};