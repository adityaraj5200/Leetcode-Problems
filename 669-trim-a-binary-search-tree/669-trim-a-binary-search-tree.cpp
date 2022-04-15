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
    TreeNode* helper(TreeNode* root, int low, int high){
        while(root && (root->val<low || root->val>high)){
            root = root->val<low ? root->right : root->left;
        }
        
        if(root != NULL){
            root->left = helper(root->left, low, high);
            root->right = helper(root->right,low,high);            
        }
        
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high){
        TreeNode *parentRoot = new TreeNode(low,root,NULL);
        // recurse(parentRoot);
        // while(root && (root->val<low || root->val>high)){
        //     root = root->val<low ? root->right ? root->left; 
        // }
        
        parentRoot->left = helper(root,low,high);
        return parentRoot->left;
    }
};