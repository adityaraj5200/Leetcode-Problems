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
    bool sawintmin=false,sawintmax=false;
    bool helper(TreeNode* root,int minval,int maxval){
        if(root == NULL) return true;
        if(root->val==INT_MIN || root->val==INT_MAX){
            if((root->val==INT_MIN && sawintmin)||(root->val==INT_MAX && sawintmax)) return false;
            
            if(root->val==INT_MIN) sawintmin = true;
            else sawintmax = true;
            
            if(root->val>maxval || root->val<minval) return false;
            return helper(root->left,minval,root->val) && helper(root->right,root->val,maxval);
        }
        
        if(root->val>=maxval || root->val<=minval) return false;
        return helper(root->left,minval,root->val) && helper(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
//         if(root->val==INT_MAX && root->right)
//             return false;
//         if(root->val==INT_MIN && root->left )
//             return false;
        return helper(root,INT_MIN,INT_MAX);
    }
};