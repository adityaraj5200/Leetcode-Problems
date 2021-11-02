class Solution {
public:
    int n,m,endx,endy,emptysquares=0,ans=0,startx,starty;
    vector<int> dx={1,0,-1,0}, dy={0,1,0,-1};
    void helper(vector<vector<int>> &grid,int emptySqLeft,int i,int j){
        if(emptySqLeft<0 || i<0 || i==n || j<0 || j==m || grid[i][j]==-1)
            return;
        if(i==endx && j==endy){
            if(emptySqLeft==0) ans++;
            return;
        }
        int val = grid[i][j];
        grid[i][j] = -1;
        for(int k=0;k<4;k++)
            helper(grid,emptySqLeft-1,i+dx[k],j+dy[k]);
        grid[i][j] = val;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) continue;
                if(grid[i][j] == 0) emptysquares++;
                else if(grid[i][j] == 1) startx=i,starty=j;
                else if(grid[i][j] == 2) endx=i,endy=j;
            }
        
        helper(grid,emptysquares+1,startx,starty);
        return ans;
    }
};