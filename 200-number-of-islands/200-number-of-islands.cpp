class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        vector<int> dx = {1,0,-1,0}, dy = {0,-1,0,1};
        
        auto isValidPosition = [&](int i,int j){
            return i>=0 && i<n && j>=0 && j<m;
        };
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] != '1')
                    continue;
                
                ans++;
                
                queue<pair<int,int>> q;
                grid[i][j] = '.'; // making it visited
                q.push({i,j});
                
                while(!q.empty()){
                    int currx = q.front().first;
                    int curry = q.front().second;
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int nextx = currx + dx[k];
                        int nexty = curry + dy[k];
                        
                        if(isValidPosition(nextx,nexty) && grid[nextx][nexty] == '1'){
                            grid[nextx][nexty] = '.';
                            q.push({nextx,nexty});
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};