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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) 
            return new TreeNode(val);
        TreeNode *parentNode = root, *currNode = root;
        while(currNode){
            parentNode = currNode;
            if(currNode->val > val)
                currNode = currNode->left;
            else
                currNode = currNode->right;
        }
        if(val > parentNode->val)
            parentNode->right = new TreeNode(val);
        else
            parentNode->left = new TreeNode(val);
        
        return root;
    }
};