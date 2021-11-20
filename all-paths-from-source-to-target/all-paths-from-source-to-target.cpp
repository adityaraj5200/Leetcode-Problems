class Solution {
public:
    void helper(int currnum,vector<bool> &vis,vector<int> &vec,vector<vector<int>> &result,vector<vector<int>> &graph){
        if(vis[currnum]) return;
        if(currnum == graph.size()-1){
            vec.push_back(graph.size()-1);
            result.push_back(vec);
            vec.pop_back();
            return;
        }
        
        vis[currnum] = true;
        vec.push_back(currnum);
        
        for(int &val: graph[currnum])
            helper(val,vis,vec,result,graph);
        
        vec.pop_back();
        vis[currnum] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<bool> vis(graph.size(),false);
        vector<int> vec;
        vector<vector<int>> result;
        helper(0,vis,vec,result,graph);
        return result;
    }
};