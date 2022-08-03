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
    int sum = 0;
    void recurse(TreeNode* root){
        if(root == NULL) return;
        
//         if(root != NULL && root->left == NULL && root->right == NULL)
//             return;
        
//         //TreeNode* temp = root;
        
//         recurse(root->right);
        
//         int a = 0;
//         if(root->right != NULL){
//             sum = root->right->val;
//         }
//         root->val = sum+root->val;
//         sum = root->val;
//         recurse(root->left);
//         root->val += sum;
//         sum = root->val;
        recurse(root->right);
        
        sum += root->val;
        root->val = sum;
        
        recurse(root->left);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        recurse(root);
        return root;
    }
};