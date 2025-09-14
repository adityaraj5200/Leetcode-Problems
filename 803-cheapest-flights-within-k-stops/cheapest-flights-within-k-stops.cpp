// Time Complexity: O(E * logV), where V = number of cities, E = number of flights
// Space Complexity: O(V + E)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adjacency list: city -> [(neighbor, price)]
        vector<vector<pair<int,int>>> graph(n);
        for(auto &f: flights){
            graph[f[0]].push_back({f[1], f[2]});
        }

        // min-heap: {cost so far, current city, stops used}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, src, 0});

        // dist[city][stops] = minimum cost to reach city using at most stops
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int cost = cur[0], u = cur[1], stops = cur[2];

            if(u == dst) return cost; // reached destination with cheapest cost

            if(stops > k) continue; // exceeded max stops allowed

            for(auto &edge : graph[u]){
                int v = edge.first, w = edge.second;
                if(cost + w < dist[v][stops+1]){
                    dist[v][stops+1] = cost + w;
                    pq.push({cost + w, v, stops+1});
                }
            }
        }
        return -1;
    }
};
