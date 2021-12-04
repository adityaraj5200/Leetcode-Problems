class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> status(n,0);
        queue<int> q;
        // debug(graph);
        
        // status:
        // 0 - not decided yet
        // 1 - keeping it in set a 
        // 2 - keeping it in set b
        
        for(int i=0;i<n;i++){
            if(status[i]) continue;
            status[i] = 1;
            q.push(i);
            bool alternate = true;
            while(!q.empty()){
                int n = q.size();
                while(n--){
                    int currNode = q.front();
                    q.pop();
                    
                    for(int &nextNode: graph[currNode]){
                        if(status[nextNode]) continue;
                        q.push(nextNode);
                        status[nextNode] = alternate ?  2 : 1;
                    }
                }
                alternate = !alternate;
            }
        }
        
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++) {
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                int n = q.size();
                while(n--){
                    int currNode = q.front();
                    q.pop();
                    
                    for(int &nextNode: graph[currNode]){
                        if(status[currNode] == status[nextNode]) 
                            return false;
                        
                        if(vis[nextNode]) continue;
                        
                        vis[nextNode] = true;
                        q.push(nextNode);
                    }
                }
            }
        }
        
        return true;
    }
};