class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n,vector<int>(n,0));

        // Adding starting and ending points to do prefix sum
        for(vector<int>& query: queries){
            int x1 = query[0];
            int y1 = query[1];
            int x2 = query[2];
            int y2 = query[3];

            for(int row=x1;row<=x2;row++){
                grid[row][y1]++;
                if(y2+1 < n){
                    grid[row][y2+1]--;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                grid[i][j] += grid[i][j-1];
            }
        }

        return grid;
    }
};