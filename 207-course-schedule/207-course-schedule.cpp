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
    
    bool dfs(int curr_node,vector<int> &status,vector<vector<int>> &adj){
        if(status[curr_node] == processed){
            return true; // we didn't found any loop afterwards
        }
        if(status[curr_node] == processing){
            return false; // A loop was detected
        }
        
        status[curr_node] = processing;
        
        for(int &next_node: adj[curr_node]){
            if(dfs(next_node,status,adj) == false){
                return false;
            }
        }
        
        status[curr_node] = processed;
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> status(numCourses,0);
        makeAdjList(prerequisites, adj);
        
        for(int curr_node=0;curr_node<numCourses;curr_node++){
            if(dfs(curr_node,status,adj) == false)
                return false;
        }
        
        return true;
    }
};