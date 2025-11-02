class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        // 0 - nothing is there
        // 1 - under the influence of guard (guard can see)
        // 2 - guard is there
        // 3 - wall is there
        for(vector<int>& v: guards){
            grid[v[0]][v[1]] = 2;
        }

        for(vector<int>& v: walls){
            grid[v[0]][v[1]] = 3;
        }

        int i,j;
        for(vector<int>& v: guards){
            i=v[0], j=v[1]+1;
            // By grid[i][j]<2 we mean that,
            // either nothing is there or is under the influence of guard
            while((i>=0 && i<m && j>=0 && j<n) && grid[i][j]<2){
                grid[i][j] = 1;
                j++;
            }

            i=v[0]-1, j=v[1];
            while((i>=0 && i<m && j>=0 && j<n) && grid[i][j]<2){
                grid[i][j] = 1;
                i--;
            }

            i=v[0], j=v[1]-1;
            while((i>=0 && i<m && j>=0 && j<n) && grid[i][j]<2){
                grid[i][j] = 1;
                j--;
            }

            i=v[0]+1, j=v[1];
            while((i>=0 && i<m && j>=0 && j<n) && grid[i][j]<2){
                grid[i][j] = 1;
                i++;
            }            
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            ans += count(grid[i].begin(),grid[i].end(),0);
        }        

        return ans;
    }
};