class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        auto validPosition = [&](int i,int j){return i>=0 && i<n && j>=0 && j<m;};
        int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = -1;
                    while(!q.empty()){
                        int sz = q.size();
                        area += sz;
                        while(sz--){
                            int x = q.front().first, y = q.front().second;
                            q.pop();
                            
                            
                            for(int k=0;k<4;k++){
                                int newx = x+dx[k], newy = y+dy[k];
                                if(validPosition(newx,newy) && grid[newx][newy]==1){
                                    grid[newx][newy] = -1; // visited
                                    q.push({newx,newy});
                                }
                            }
                        }
                    }
                    
                    ans = max(ans, area);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == -1)
                    grid[i][j] = 1;
            }
        }
        
        return ans;
    }
};