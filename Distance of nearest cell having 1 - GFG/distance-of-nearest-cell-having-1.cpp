// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size(), currDist = 0;
	    vector<vector<int>> result = grid;
	    
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j] == 1){
	                result[i][j] = 0;
	                q.push({i,j});
	            }
	            else{
	                result[i][j] = 1e9;
	            }
	        }
	    }
	    
        vector<int> dirx = {1,0,-1,0}, diry = {0,-1,0,1};
        auto isvalidpos = [&](int i,int j){
            return i>=0 && i<n && j>=0 && j<m;
        };
	    while(!q.empty()){
	        int sz = q.size();
	        currDist++;
	        while(sz--){
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            for(int k=0;k<4;k++){
	                int newx = x+dirx[k];
	                int newy = y+diry[k];
	                if(!isvalidpos(newx,newy)) continue;
	                if(currDist < result[newx][newy]){
	                    q.push({newx,newy});
	                    result[newx][newy] = currDist;
	                }
	            }
	        }
	    }
	    return result;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends