/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool helper(TreeNode *root,TreeNode *reqNode,vector<TreeNode*> &vec){
        if(root == NULL) return false;
        vec.push_back(root);
        if(root == reqNode) return true;
        if(helper(root->left,reqNode,vec) || helper(root->right,reqNode,vec))
            return true;
        vec.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vec1, vec2;
        helper(root,p,vec1);
        helper(root,q,vec2);
        TreeNode *ans;
        for(int i=0;i<min(vec1.size(),vec2.size());i++){
            if(vec1[i] == vec2[i])
                ans = vec1[i];
            else break;
        }
        return ans;
    }
};