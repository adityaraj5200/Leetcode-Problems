class Solution {
public:
    bool helper(vector<vector<int>> &vec,vector<bool> &vis,int start,int end) {
        if(start == end) return true;
        if(vis[start]) return false;
        vis[start] = true;
        for(int i=0;i<vec[start].size();i++)
            if(helper(vec,vis,vec[start][i],end))
                return true;
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> vec(n);
        vector<bool> vis(n,false);
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0], y = edges[i][1];
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        return helper(vec,vis,start,end);
    }
};