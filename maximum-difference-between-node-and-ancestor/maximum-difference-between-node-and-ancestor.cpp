class Solution {
public:  
  int maxAncestorDiff(TreeNode *root) {
    int answer = 0;
    if(root){
      queue<tuple<TreeNode *, int, int>>q;
      q.push({root, root->val, root->val});
      while(!q.empty()){
        auto [node, maxi, mini] = q.front(); q.pop();
        
        maxi = max(maxi, node->val);
        mini = min(mini, node->val);
        answer = max(answer, maxi - mini);
        
        if(node->left ) q.push({node->left , maxi, mini});
        if(node->right) q.push({node->right, maxi, mini});
      }
    }
    
    return answer;
  }
};