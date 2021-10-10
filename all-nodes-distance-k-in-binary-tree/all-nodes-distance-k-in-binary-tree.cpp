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
    unordered_map<TreeNode*, TreeNode*> m; // child,parent
    void fillmap(TreeNode* root){
        if(root->left){
            m[root->left] = root;
            fillmap(root->left);
        }
        if(root->right){
            m[root->right] = root;
            fillmap(root->right);
        }
    }
    vector<int> result;
    void helper(TreeNode *root,int dist,int &k){
        if(root == NULL || root->val==-1 || dist > k) return;
        if(dist==k){
            result.push_back(root->val);
            return;
        }
        root->val = -1;
        helper(m[root], dist+1, k);
        helper(root->left,dist+1,k);
        helper(root->right,dist+1,k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        m[root] = NULL;
        fillmap(root);
        helper(target,0,k);
        return result;
    }
};