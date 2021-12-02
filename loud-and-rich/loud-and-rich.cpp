class Solution {
public:
    int dfs(unordered_map<int,vector<int>> &graph,vector<int> &ans,vector<int>& quiet,int &i){
        if(ans[i] != -1) return ans[i];
        ans[i] = i;
        for(int &nextPerson: graph[i])
            if(quiet[ans[i]] > quiet[dfs(graph,ans,quiet,nextPerson)])
                ans[i] = ans[nextPerson];
        return ans[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int,vector<int>> graph;
        for(auto &rich: richer)
            graph[rich[1]].push_back(rich[0]);
        
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
            dfs(graph,ans,quiet,i);
        
        return ans;
    }
};