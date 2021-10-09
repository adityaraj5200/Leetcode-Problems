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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode node(INT_MAX,root,NULL), *curr = &node, *preroot = curr;
        
        while(curr){
            if(curr->val>key){
                if(curr->left && curr->left->val != key) curr = curr->left;
                else break;
            }
            else if(curr->val<key){
                if(curr->right && curr->right->val != key) curr = curr->right;
                else break;
            }
        }
        if(curr == NULL) return root;
        
        if(curr->val < key){
            TreeNode *del = curr->right;
            if(del==NULL) return preroot->left;
            if(del->left==NULL || del->right==NULL)
                curr->right = del->left ? del->left : del->right;
            else{
                TreeNode *temp = del->right;
                while(temp->left) temp = temp->left;
                temp->left = del->left;
                del->left = NULL;
                curr->right = del->right;
            }
        }
        else{
            TreeNode *del = curr->left;
            if(del==NULL) return preroot->left;
            if(del->left==NULL || del->right==NULL)
                curr->left = del->left ? del->left : del->right;
            else{
                TreeNode *temp = del->right;
                while(temp->left) temp = temp->left;
                temp->left = del->left;
                del->left = NULL;
                curr->left = del->right;
            }
        }
        
        return preroot->left;
    }
};