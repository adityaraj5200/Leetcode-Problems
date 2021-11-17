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
    void helper(TreeNode *root, vector<int> &freq, int &ans){
        if(root==NULL) return;
        freq[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int oddcnt = 0;
            for(int &val: freq)
                if(val&1)
                    oddcnt++;
            freq[root->val]--;
            if(oddcnt < 2)
                ans++;
            return;
        }
        helper(root->left,freq,ans);
        helper(root->right,freq,ans);
        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        int ans = 0;
        helper(root,freq,ans);
        return ans;
    }
};