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
    bool helper(TreeNode* currnode, vector<TreeNode*>& vec, TreeNode* reqnode){
        if(currnode==NULL) return false;
        vec.push_back(currnode);
        if(currnode == reqnode) return true;
        if(helper(currnode->left, vec, reqnode) || helper(currnode->right, vec, reqnode))
            return true;
        vec.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        helper(root,path1,p);
        helper(root,path2,q);
        
        TreeNode *ans = NULL;
        for(int i=0;i<min(path1.size(),path2.size());i++)
            if(path1[i] == path2[i])
                ans = path1[i];
        return ans;
        
    }
};