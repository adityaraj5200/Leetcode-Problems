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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        long long ans = 0;
        root->val = 1;
        
        while(!q.empty()){
            int sz = q.size();
            long long toSubtract = q.front()->val - 1;
            long long minval = q.front()->val, maxval;
            
            while(sz--){
                TreeNode *node = q.front();
                q.pop();
                
                maxval = node->val;
                
                node->val -= toSubtract;
                if(node->left){
                    node->left->val = node->val*2LL ;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = node->val*2LL + 1LL;
                    q.push(node->right);
                }
            }
            
            ans = max(ans,maxval-minval+1LL);
        }
        return (int)ans;
    }
};