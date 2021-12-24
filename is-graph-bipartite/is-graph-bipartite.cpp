class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> status(n,-1);
        queue<int> q;
        // status:
        // -1 - not decided yet
        // 0 - keeping it in set a 
        // 1 - keeping it in set b
        
        for(int i=0;i<n;i++){
            if(status[i] != -1) continue;
            
            int color = 0, prev = -1;
            q.push(i);
            status[i] = color;
            while(!q.empty()){
                int n = q.size();
                color = !color;
                while(n--){
                    int currNode = q.front();
                    q.pop();
                    
                    for(int &nextNode: graph[currNode]){
                        if(status[nextNode] == !color)
                            return false;
                        if(status[nextNode] == -1){
                            status[nextNode] = color;
                            q.push(nextNode);
                        }
                    }
                }
            }
        }
        
        return true;
    }
}; 