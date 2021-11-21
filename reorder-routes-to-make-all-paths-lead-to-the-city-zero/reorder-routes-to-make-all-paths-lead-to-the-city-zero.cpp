class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &vec: connections){
            int u = vec[0], v = vec[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
            // 1 denotes child
            // 0 denotes parent
        }
        
        vector<bool> vis(n,false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int toReverse = 0;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto &adjNode: adj[currNode]){
                int newNode = adjNode.first;
                int relation = adjNode.second;
                if(vis[newNode]) continue;
                vis[newNode] = true;
                if(relation == 1) toReverse++;
                q.push(newNode);
            }
        }
        return toReverse;
    }
};