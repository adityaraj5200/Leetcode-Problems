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
    map<int,int> m;
    TreeNode* helper(vector<int>& pre,int pst,int pend,vector<int>& in,int inst,int inend){
        if(pst > pend || inst > inend) return NULL;
        TreeNode* root = new TreeNode(pre[pst]);
        int idx = m[pre[pst]], numsleft = idx - inst;
        root->left = helper(pre,pst+1,pst+numsleft,in,inst,idx-1);
        root->right = helper(pre,pst+numsleft+1,pend,in,idx+1,inend);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};