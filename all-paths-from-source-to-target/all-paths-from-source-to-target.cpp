class Solution {
public:
    void helper(int &currNode,vector<bool> &vis,vector<int> &path,vector<vector<int>> &result,vector<vector<int>> &graph){
        if(vis[currNode]) return;
        if(currNode == graph.size()-1){
            path.push_back(currNode);
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        vis[currNode] = true;
        path.push_back(currNode);
        
        for(int &nextNode: graph[currNode])
            helper(nextNode,vis,path,result,graph);
        
        path.pop_back();
        vis[currNode] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<bool> vis(graph.size(),false);
        vector<int> path;
        vector<vector<int>> result;
        int currNode = 0;
        helper(currNode,vis,path,result,graph);
        return result;
    }
};