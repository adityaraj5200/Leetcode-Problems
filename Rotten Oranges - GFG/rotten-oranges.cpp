// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        int dirx[4] = {1,0,-1,0}, diry[4] = {0,-1,0,1}; 
        int ans = 0, currlevel = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        // return currlevel;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                auto isvalidpos = [&](int i,int j){
                    return i>=0 && i<n && j>=0 && j<m;
                };
                
                for(int k=0;k<4;k++){
                    int newx = x+dirx[k];
                    int newy = y+diry[k];
                    if(isvalidpos(newx,newy) && grid[newx][newy]==1){
                        grid[newx][newy] = 2;
                        q.push({newx,newy});
                    }
                }
                
            }
            currlevel += !q.empty();
        }
        
        for(auto &vec: grid){
            for(auto &val: vec){
                if(val==1)
                    return -1;
            }
        }
        
        return currlevel;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends