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
    TreeNode *preroot, *curr;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        curr = curr->right = root;
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        curr = preroot = new TreeNode(-1,NULL,root);
        inorder(root);
        curr = preroot;
        
        while(curr != NULL){
            curr->left = NULL;
            curr = curr->right;
        }
        
        return preroot->right;
    }
};