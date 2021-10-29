class Solution {
public:
    bool isValidPos(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int cnt = 0, n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 2)
                    q.push({i,j});
        
        vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            bool added = false;
            while(size--){
                int i = q.front().first, j = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int x = i+dx[k], y = j+dy[k];
                    if(isValidPos(x,y,n,m) && grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y] = 2;
                        added = true;
                    }
                }
            }
            cnt += added;
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    return -1;
        return cnt;
    }
};