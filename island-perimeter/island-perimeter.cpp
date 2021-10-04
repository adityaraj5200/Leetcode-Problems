class Solution {
public:
    bool isvalid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size(),dx4[4]={1,0,-1,0},dy4[4]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int x = i+dx4[k], y = j+dy4[k];
                    if(grid[i][j] && (!isvalid(x,y,n,m) || grid[x][y]==0))
                        cnt++;
                }
            }
        }
        return cnt;
    }
};