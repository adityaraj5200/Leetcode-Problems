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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        queue<TreeNode*> q;
        if(root != NULL)
            q.push(root);

        while(!q.empty()){
            int sz = q.size();
            int last = -1;
            while(sz--){
                TreeNode* node = q.front();
                last = node->val;
                q.pop();

                // cout<<node->data<<' ';

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
            ans.push_back(last);
        }
        
        return ans;
    }
};