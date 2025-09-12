class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for(vector<int>& row: grid){
            sort(row.begin(),row.end());
        }

        for(int j=m-1;j>=0;j--){
            int mx = INT_MIN;
            for(int i=0;i<n;i++){
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }

        return ans;
    }
};