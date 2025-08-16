class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto& edge : edges){
            int u = edge[0], v =edge[1], w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u, 2*w});
        }
        vector<int>dist(n, INT_MAX);
        priority_queue<pair<int, int>,
            vector<pair<int,int>>, greater<pair<int, int>>>pq;
        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            auto[d, u] = pq.top(); pq.pop();
                if(d>dist[u]) continue;
            if(u == n-1)return d;
            for(auto[v,w] : adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};