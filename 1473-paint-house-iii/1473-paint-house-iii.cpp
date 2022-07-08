class Solution{
public:
    int dp[101][101][21] = {};
    
    int recurse(vector<int>& houses,vector<vector<int>> &cost,int idx,int target,int last_color){
        if(idx==houses.size() || target<0)
            return target==0 ? 0 : 1e9;
        
        if(houses[idx] != 0){
            return dp[idx][target][last_color] = recurse(houses,cost,idx+1,target-(last_color!=houses[idx]),houses[idx]);
            // return recurse(houses,cost,idx+1,target-(last_color!=houses[idx]),houses[idx]);
        }
        
        if(dp[idx][target][last_color] != 0)
            return dp[idx][target][last_color];
        
        int ans = 1e9;
        for(int color=1 ; color<=cost[idx].size() ; color++){
            int cost_with_this_color = cost[idx][color-1] + recurse(houses,cost,idx+1,target-(color!=last_color),color);
            ans = min(ans,cost_with_this_color);
        }
        
        return dp[idx][target][last_color] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        int ans = recurse(houses,cost,0,target,0);
        return ans==1e9 ? -1 : ans;
    }
};