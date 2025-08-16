class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],2*edge[2]});
        }
        
        vector<int> minDist(n,1e9);
        minDist[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); // {costSoFar, node}

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

    
            if(d > minDist[u]) continue;
            if(u==n-1) return d; // Reached destination
    
            for(auto [v, wt] : adj[u]) {
                if(minDist[u] + wt < minDist[v]) {
                    minDist[v] = minDist[u] + wt;
                    pq.push({minDist[v], v});
                }
            }
        }

        return -1;
    }
};