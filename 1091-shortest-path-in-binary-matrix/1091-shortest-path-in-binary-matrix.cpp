class Solution {
public:
    vector<int> dir = {1,0,-1};
    bool isValidPosition(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;    
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        dp[0][0] = 1;
        
        queue<vector<int>> q; // {x,y,mincost};
        q.push({0,0,1});
        
        while(!q.empty()){
            vector<int> vec = q.front();
            q.pop();
            
            int x = vec[0], y = vec[1], cost_till_here = vec[2];
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int newx = x+dir[i], newy = y+dir[j];
                    if(isValidPosition(newx,newy,n,m) && grid[newx][newy]==0 && dp[newx][newy] > cost_till_here + 1){
                        dp[newx][newy] = cost_till_here + 1;
                        q.push({newx,newy,cost_till_here+1});
                    }
                }
            }
        }
        
        return dp[n-1][m-1]==1e9 ? -1 : dp[n-1][m-1];
    }
};