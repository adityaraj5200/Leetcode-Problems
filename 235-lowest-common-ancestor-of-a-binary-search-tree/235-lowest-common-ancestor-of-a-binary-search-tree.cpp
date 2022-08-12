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
    bool getPath(TreeNode* root,int req_value,vector<TreeNode*> &path){
        if(root==NULL) return false;
        
        path.push_back(root);
        
        if(root->val == req_value)
            return true;
        
        if(getPath(root->left, req_value, path)) return true;
        if(getPath(root->right, req_value, path)) return true;
        
        path.pop_back();
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        getPath(root,p->val,path1);
        getPath(root,q->val,path2);
        
        TreeNode *resulting_node = NULL;
        for(int i=0;i<min(path1.size(),path2.size()) && path1[i]==path2[i];i++){
            resulting_node = path1[i];
        }
        
        return resulting_node;
    }
};