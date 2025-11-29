class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return dfs(0, k, 0, prices);
    }

private:
    vector<vector<vector<int>>> memo;

    int dfs(int i, int trans, int holding, vector<int>& prices) {
        int n = prices.size();
        if (i >= n || trans == 0 && holding == 0) {
            return 0;
        }

        if (memo[i][trans][holding] != -1) return memo[i][trans][holding];

        int ans = INT_MIN;
        if (holding) {
            int skip = dfs(i+1, trans, holding, prices);
            int sell = prices[i] + dfs(i+1, trans-1, 0, prices);
            ans = max(skip, sell);
        } else {
            int skip = dfs(i+1, trans, holding, prices);
            int buy = -prices[i] + dfs(i+1, trans, 1, prices);
            ans = max(skip, buy);
        }
        return memo[i][trans][holding] = ans;
    }
};
