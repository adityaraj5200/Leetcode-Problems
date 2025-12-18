class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        int n = prices.length;
        int half = k / 2;

        // Base profit using original strategy
        long baseProfit = 0;
        long[] contrib = new long[n]; // prices[i] * strategy[i]
        for (int i = 0; i < n; i++) {
            contrib[i] = (long) prices[i] * strategy[i];
            baseProfit += contrib[i];
        }

        // Sliding window:
        // origWindow = original contribution in window
        // modWindow  = modified contribution (0 for first half, +prices for second half)
        long origWindow = 0;
        long modWindow = 0;

        // Initialize first window [0 .. k-1]
        for (int i = 0; i < k; i++) {
            origWindow += contrib[i];
            if (i >= half) {
                modWindow += prices[i];
            }
        }

        long maxGain = modWindow - origWindow;

        // Slide window
        for (int start = 1; start + k <= n; start++) {
            int end = start + k - 1;

            origWindow += contrib[end] - contrib[start - 1];
            modWindow += prices[end] - prices[start - 1 + half];

            maxGain = Math.max(maxGain, modWindow - origWindow);
        }

        // Apply the best improvement if positive
        return baseProfit + Math.max(0, maxGain);
    }
}