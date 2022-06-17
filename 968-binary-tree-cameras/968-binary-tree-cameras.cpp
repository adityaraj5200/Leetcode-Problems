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
    // Messages Nodes are sending to their parent node
    #define HAVE 0 // The node is saying that I have camera so I am covering myself and I will also cover you
    #define COVERED 1 // The node is saying I am covered, you arrange for yourself
    #define NEED 2 // The node is saying I am not covered in anyway so install camera for me.
    
    int ans = 0;
    
    int getStatus(TreeNode* root){
        if(root==NULL) return COVERED;
        
        int leftStatus = getStatus(root->left);
        int rightStatus = getStatus(root->right);
        
        if(leftStatus==NEED || rightStatus==NEED){
            // If any child said they need camera then install camera, and give message to the parent that you 'HAVE' the camera.
            
            ans++; // incrementing the camera count
            return HAVE;
        }
        
        if(leftStatus==HAVE || rightStatus==HAVE){
            // If any of the child said that they have the camera then I will tell my parent that I do not have the camera but I am 'COVERED'
            return COVERED;
        }
        
        // if control reached here that means both left and right child are saying they are covered. So I am not covered by anyone so I 'NEED' my parent to install camera.
        return NEED;
        
    }
    
    int minCameraCover(TreeNode* root) {
        if(getStatus(root) == NEED) ans++; // When the root node itself is a leaf node then we need at least one camera.
        
        return ans;
    }
};