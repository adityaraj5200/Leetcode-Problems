class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        for(vector<int>& vec: edges)
            vis[vec[1]] = true;
        vector<int> result;
        for(int i=0,n=vis.size();i<n;i++)
            if(!vis[i])
                result.push_back(i);
        return result;
    }
};