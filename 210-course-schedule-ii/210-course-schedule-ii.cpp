class Solution {
public:
    void makeAdjList(vector<vector<int>> &prerequisites,vector<vector<int>> &adj){
        for(vector<int> &v: prerequisites){
            adj[v[1]].push_back(v[0]); // create a directed edge
        }
    }
    
    #define unvisited 0
    #define processed 1
    #define processing 2
    bool detect_loop(int curr_node,vector<int> &status,vector<vector<int>> &adj){
        if(status[curr_node] == processed)
            return false; // we didn't found any loop afterwards
        if(status[curr_node] == processing)
            return true; // A loop was detected
        
        status[curr_node] = processing;
        
        for(int &next_node: adj[curr_node])
            if(detect_loop(next_node,status,adj))
                return true;
        
        status[curr_node] = processed;
        
        return false;
    }
    
    void dfs(int curr_node,vector<vector<int>> &adj,stack<int> &stk,vector<bool> &visited){
        if(visited[curr_node])
            return;
        
        visited[curr_node] = true;
        for(int &next_node: adj[curr_node]){
            dfs(next_node,adj,stk,visited);
        }
        
        stk.push(curr_node);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> status(numCourses,0);
        vector<vector<int>> adj(numCourses);
        
        makeAdjList(prerequisites,adj);
        
        for(int i=0;i<numCourses;i++)
            if(detect_loop(i,status,adj))
                return {};
        
        stack<int> stk;
        vector<bool> visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            dfs(i,adj,stk,visited);
        }
        
        vector<int> ans;
        while(stk.empty() == false){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        return ans;
    }
};