class Solution {

    private long[][][] dp;
    private int n;

    private static final int IDLE = 0;
    private static final int BOUGHT = 1;
    private static final int SHORT_SOLD = 2;

    public long maximumProfit(int[] prices, int k) {
        n = prices.length;
        dp = new long[n][k + 1][3];

        // Initialize DP with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = 0; s < 3; s++) {
                    dp[i][j][s] = -1;
                }
            }
        }

        return helper(0, k, IDLE, prices);
    }

    private long helper(int idx, int k, int state, int[] prices) {
        if (idx == n) {
            return state == IDLE ? 0 : Long.MIN_VALUE / 2;
        }

        if (dp[idx][k][state] != -1) {
            return dp[idx][k][state];
        }

        long ans = Long.MIN_VALUE;

        if (state == IDLE) {
            long skip = helper(idx + 1, k, state, prices);
            long buy = k > 0
                    ? -prices[idx] + helper(idx + 1, k - 1, BOUGHT, prices)
                    : Long.MIN_VALUE;
            long shortSell = k > 0
                    ? prices[idx] + helper(idx + 1, k - 1, SHORT_SOLD, prices)
                    : Long.MIN_VALUE;

            ans = Math.max(skip, Math.max(buy, shortSell));

        } else if (state == BOUGHT) {
            long skip = helper(idx + 1, k, state, prices);
            long sell = prices[idx] + helper(idx + 1, k, IDLE, prices);
            ans = Math.max(skip, sell);

        } else { // SHORT_SOLD
            long skip = helper(idx + 1, k, state, prices);
            long buy = -prices[idx] + helper(idx + 1, k, IDLE, prices);
            ans = Math.max(skip, buy);
        }

        return dp[idx][k][state] = ans;
    }
}
