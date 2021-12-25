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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({original,cloned});
        while(!q.empty()){
            TreeNode *node = q.front().first, *clonedNode = q.front().second;
            q.pop();
            if(node == target)
                return clonedNode;
            if(node->left) q.push({node->left,clonedNode->left});
            if(node->right) q.push({node->right,clonedNode->right});
        }
        return NULL;
    }
};