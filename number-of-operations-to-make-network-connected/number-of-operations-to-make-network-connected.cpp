class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int currNode){
        vis[currNode] = true;
        for(int &neighbourNode: adj[currNode]){
            if(!vis[neighbourNode])
                dfs(adj,vis,neighbourNode);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        // This problem is like counting number of islands
        int numCables = connections.size();
        if(numCables < n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto &edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(n,false);
        int bunches = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bunches++;
                dfs(adj,vis,i);
            }
        }
        return bunches-1;
    }
};