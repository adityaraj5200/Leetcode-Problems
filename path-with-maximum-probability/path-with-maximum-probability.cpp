class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            vector<int> &e = edges[i];
            adj[e[0]].push_back(make_pair(succProb[i],e[1]));
            adj[e[1]].push_back(make_pair(succProb[i],e[0]));
        }
        
        priority_queue<pair<double, int>> pq;
        pq.push({1.0,start});
        
        vector<double> prob(n,0.0);
        prob[start] = 1.0;
        
        while(!pq.empty()){
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            for(auto &p: adj[currNode]){
                double nextProb = p.first;
                int nextNode = p.second;
                if(prob[nextNode] < currProb * nextProb){
                    prob[nextNode] = currProb * nextProb;
                    pq.push({prob[nextNode],nextNode});
                }
            }
        }
        return prob[end];
    }
};