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
    bool isCousins(TreeNode* root, int x, int y){
        if(root->val==x || root->val==y) return false;
        queue<TreeNode*> q;
        q.push(NULL);
        q.push(root);
        bool foundx = false, foundy = false;
        TreeNode *node1,*node2;
        while(!q.empty()){
            if(foundx || foundy) return false;
            int size = q.size()/2;
            // cout<<"stk.size() = "<<stk.size()<<endl;
            while(size--){
                node1 = q.front();
                q.pop();
                node2 = q.front();
                q.pop();
                
                bool justfoundx = false, justfoundy = false;
                if(node1){
                    // cout<<node1->val<<' ';
                    if(node1->val==x) justfoundx = foundx = true;
                    else if(node1->val==y) justfoundy = foundy = true;
                    q.push(node1->left);
                    q.push(node1->right);
                }
                // else cout<<"N ";
                if(node2){
                    cout<<node2->val<<' ';
                    if(node2->val==x) justfoundx = foundx = true;
                    else if(node2->val==y) justfoundy = foundy = true;
                    q.push(node2->left);
                    q.push(node2->right);
                }
                // else cout<<"N ";
                // cout<<endl;
                if(justfoundx && justfoundy) return false;
                if(foundx && foundy) return true;
            }
        }
        return false;
    }
};