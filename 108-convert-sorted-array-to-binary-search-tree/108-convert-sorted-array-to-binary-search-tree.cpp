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
    // TreeNode *root;
    // bool encounteringFirstNode = true;
    
    TreeNode* helper(int st,int end,vector<int> &nums){
        if(st > end)
            return NULL;
        
        int mid = (st+end)>>1;
        
        return new TreeNode(nums[mid],helper(st,mid-1,nums),helper(mid+1,end,nums));
        
        // node->left = helper(st,mid-1,nums);
        // node->right = helper(mid+1,end,nums);
        
        // return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0,nums.size()-1,nums);
        // return root;
    }
};