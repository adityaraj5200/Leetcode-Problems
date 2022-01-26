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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        queue<TreeNode*> q;
        if(root1 != NULL) q.push(root1);
        if(root2 != NULL) q.push(root2);
        while(!q.empty()){
            TreeNode *currNode = q.front();
            q.pop();
            result.push_back(currNode->val);
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        sort(result.begin(), result.end());
        return result;
    }
};