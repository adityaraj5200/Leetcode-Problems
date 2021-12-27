class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e: times)
            adj[e[0]].push_back({e[2],e[1]});
        
        vector<int> time(n+1,1e9);
        time[0] = time[k] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            int currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(auto &p: adj[currNode]){
                int nextTime = p.first;
                int nextNode = p.second;
                if(time[nextNode] > currTime + nextTime){
                    time[nextNode] = currTime + nextTime;
                    pq.push({time[nextNode],nextNode});
                }
            }
        }
        
        int ans = *max_element(time.begin(),time.end());
        return ans==1e9 ? -1 : ans;
    }
};