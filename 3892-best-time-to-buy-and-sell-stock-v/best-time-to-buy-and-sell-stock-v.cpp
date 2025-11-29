class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp = vector<vector<vector<long long>>>(n,vector<vector<long long>>(k + 1, vector<long long>(3, -1)));

        return helper(0,k,idle,prices);
    }
private:
    vector<vector<vector<long long>>> dp;
    int n;
    const int idle = 0, bought = 1, shortSold = 2;
    long long helper(int idx, int k, int state, vector<int>& prices){
        if(idx==n){
            return state==idle ? 0 : LLONG_MIN/2;
        }

        if(dp[idx][k][state]!=-1) return dp[idx][k][state];

        long long ans = LLONG_MIN;
        if(state==idle){
            long long skip = helper(idx+1,k,state,prices);
            long long buy = k>0 ? 1LL*(-prices[idx])+helper(idx+1,k-1,bought,prices) : 0;
            long long shortSell = k>0 ? 1LL*prices[idx]+helper(idx+1,k-1,shortSold,prices) : 0;
            ans = max({skip, buy, shortSell});
        }
        else if(state==bought){
            long long skip = helper(idx+1,k,state,prices);
            long long sell = 1LL*prices[idx] + helper(idx+1,k,idle, prices);
            ans = max(skip, sell);
        }
        else{
            long long skip = helper(idx+1,k,state,prices);
            long long buy = 1LL*(-prices[idx]) + helper(idx+1,k,idle, prices);
            ans = max(skip, buy);
        }

        return dp[idx][k][state] = ans;
    }
};