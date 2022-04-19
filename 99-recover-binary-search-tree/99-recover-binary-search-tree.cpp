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
    TreeNode* firstNode = NULL, *secondNode = NULL, *prevNode = NULL;
    void inorder(TreeNode *root){
        if(root==NULL) return;
        
        inorder(root->left);
        
        if(firstNode==NULL && prevNode!=NULL && root->val<=prevNode->val)
            firstNode = prevNode;
        if(firstNode!=NULL && prevNode!=NULL && root->val<=prevNode->val)
            secondNode = root;
        
        prevNode = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(firstNode->val, secondNode->val);
    }
};