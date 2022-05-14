class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e: times)
            adj[e[0]].push_back({e[2],e[1]});
        
        vector<int> dp(n+1,1e9); // stores the min time to reach any node from node k.
        dp[0] = dp[k] = 0; // 0 node doesn't exist. And node k to node k doesn't make any sense
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k}); // {time to reach any node, that node}
        
        while(!pq.empty()){
            int currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(auto &p: adj[currNode]){
                int nextTime = p.first;
                int nextNode = p.second;
                if(dp[nextNode] > currTime + nextTime){
                    dp[nextNode] = currTime + nextTime;
                    pq.push({dp[nextNode],nextNode});
                }
            }
        }
        
        int ans = *max_element(dp.begin(),dp.end());
        return ans==1e9 ? -1 : ans;
    }
};