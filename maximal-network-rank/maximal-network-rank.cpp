class Solution {
public:
    bool isConnected(vector<vector<int>> &graph,int &city1, int &city2){
        for(int &nextCity: graph[city1])
            if(nextCity == city2)
                return true;
        return false;
    }
    
    int getNetworkRank(vector<vector<int>> &graph,int &city1,int &city2){
        return graph[city1].size() + graph[city2].size() - isConnected(graph,city1,city2);
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);
        for(auto &road: roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ans = max(ans,getNetworkRank(graph,i,j));
        return ans;
    }
};