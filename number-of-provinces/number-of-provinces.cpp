class Solution {
public:
    void dfs(int currCity,vector<vector<int>>& isConnected,vector<bool> &vis){
        for(int i=0,n=isConnected.size();i<n;i++){
            if(isConnected[currCity][i] && !vis[i]){
                vis[i] = true;
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), cnt = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(isConnected[i][j] && !vis[i]){
                    cnt++;
                    vis[i] = true;
                    dfs(i,isConnected,vis);
                }
        return cnt;
    }
};