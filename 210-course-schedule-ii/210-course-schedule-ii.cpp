class Solution {
public:
    void makeAdjList(vector<vector<int>> &prerequisites,vector<vector<int>> &adj){
        for(vector<int> &v: prerequisites){
            adj[v[1]].push_back(v[0]); // create a directed edge
        }
    }
    
//     bool detect_loop(int curr_node,vector<int> &status,vector<vector<int>> &adj){
//         if(status[curr_node] == processed)
//             return false; // we didn't found any loop afterwards
//         if(status[curr_node] == processing)
//             return true; // A loop was detected
        
//         status[curr_node] = processing;
        
//         for(int &next_node: adj[curr_node])
//             if(detect_loop(next_node,status,adj))
//                 return true;
        
//         status[curr_node] = processed;
        
//         return false;
//     }
    
    #define unvisited 0
    #define processed 1
    #define processing 2
    bool dfs(int curr_node,vector<vector<int>> &adj,stack<int> &stk,vector<int> &status){
        if(status[curr_node] == processed)
            return true; // we didn't found any loop afterwards
        if(status[curr_node] == processing)
            return false; // A loop was detected
        
        status[curr_node] = processing;
        
        for(int &next_node: adj[curr_node]){
            if(dfs(next_node,adj,stk,status) == false)
                return false;
        }
        
        status[curr_node] = processed;
        
        stk.push(curr_node);
        
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> status(numCourses,0);
        vector<vector<int>> adj(numCourses);
        
        makeAdjList(prerequisites,adj);
        
        stack<int> stk;
        for(int i=0;i<numCourses;i++){
            if(dfs(i,adj,stk,status) == false)
                return {};
        }
        
        vector<int> ans;
        while(stk.empty() == false){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        return ans;
    }
};