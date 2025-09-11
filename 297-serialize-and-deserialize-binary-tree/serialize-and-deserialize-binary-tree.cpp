/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec{
public:
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        string serialized;
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            serialized += (node==NULL ? "n" : to_string(node->val)) + ",";

            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }

        return serialized;
    }

    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        for(int i=0;i<data.length();i++){
            if(data[i]=='n'){
                nodes.push_back(NULL);
                i++;
            } else {
                int sign = 1;
                if(data[i]=='-'){
                    sign = -1;
                    i++;
                }
                int num=0;
                while(i<data.length() && data[i]!=','){
                    num = num*10+(data[i]-'0');
                    i++;
                }
                nodes.push_back(new TreeNode(num*sign));
            }
        }

        int n=nodes.size(), parentIdx=0, childIdx=1;
        while(parentIdx<n && childIdx<n){
            if(nodes[parentIdx]){
                if(childIdx<n) nodes[parentIdx]->left=nodes[childIdx++];
                if(childIdx<n) nodes[parentIdx]->right=nodes[childIdx++];
            }
            parentIdx++;
        }

        return nodes[0];
    }
};