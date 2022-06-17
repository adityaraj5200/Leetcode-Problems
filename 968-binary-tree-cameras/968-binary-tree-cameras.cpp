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
    #define HAVE 0
    #define COVERED 1
    #define NEED 2
    
    int ans = 0;
    
    int getStatus(TreeNode* root){
        if(root==NULL) return COVERED;
        
        int leftStatus = getStatus(root->left);
        int rightStatus = getStatus(root->right);
        
        if(leftStatus==NEED || rightStatus==NEED){
            ans++;
            return HAVE;
        }
        
        if(leftStatus==HAVE || rightStatus==HAVE){
            return COVERED;
        }
        
        return NEED;
        
    }
    
    int minCameraCover(TreeNode* root) {
        if(getStatus(root) == NEED) ans++;
        return ans;
    }
};