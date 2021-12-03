class Solution {
public:
    bool isSafeNode(int &i,vector<vector<int>>& graph,vector<int>& status){
        if(status[i] != -1) 
            return status[i];
        //status: 
        // (-1) - can't say anything now,
        // 1 - safe,
        // 0 - not safe(leads to loop).
        status[i] = 0;
        for(int &nextNode: graph[i])
            if(!isSafeNode(nextNode,graph,status))
                return false;
        
        //all next nodes were safe, that means my current node is also a safe Node.
        return status[i]=1;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> status(n,-1), ans;
        for(int i=0;i<n;i++)
            if(isSafeNode(i,graph,status))
                ans.push_back(i);
        return ans;
    }
};