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
    TreeNode *firstNode = NULL, *secondNode = NULL, *prevNode = NULL;
    
    void helper(TreeNode* root){
        if(root==NULL) return;
        
        helper(root->left);
        
        if(prevNode!=NULL && prevNode->val > root->val){
            if(firstNode == NULL) 
                firstNode = prevNode;
            
            if(firstNode != NULL)
                secondNode = root;
        }
        prevNode = root;
        
        helper(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(firstNode->val, secondNode->val);
    }
};