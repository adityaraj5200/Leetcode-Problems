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
    TreeNode* helper(vector<int>& inorder,int inst,int inend,vector<int>& postorder,int post,int poend){
        if(inst > inend || post > poend) return NULL;
        TreeNode* root = new TreeNode(postorder[poend]);
        int idx = m[root->val], numsleft = idx-inst, numsright = inend-idx;
        root->left = helper(inorder,inst,idx-1,postorder,post,post+numsleft-1);
        root->right = helper(inorder,idx+1,inend,postorder,poend-numsright,poend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};