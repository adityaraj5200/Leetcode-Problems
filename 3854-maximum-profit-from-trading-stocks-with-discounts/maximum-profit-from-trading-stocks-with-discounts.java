class Solution {
    int n, budget;
    List<Integer>[] children;
    int[] present, future;

    public int maxProfit(int n, int[] present, int[] future, int[][] hierarchy, int budget) {
        this.n = n;
        this.budget = budget;
        this.present = present;
        this.future = future;
        
        children = new ArrayList[n];
        for (int i = 0; i < n; i++) children[i] = new ArrayList<>();
        for (int[] e : hierarchy)
            children[e[0] - 1].add(e[1] - 1);

        // dp[0] for no discount from boss, dp[1] for with discount
        int[][] rootDP = dfs(0);
        int ans = 0;
        for (int b = 0; b <= budget; b++)
            ans = Math.max(ans, rootDP[0][b]);
        return ans;
    }

    private int[][] dfs(int u) {
        // Start dp arrays
        int[] dpNo = new int[budget + 1];
        int[] dpWith = new int[budget + 1];

        // Merge children first
        for (int v : children[u]) {
            int[][] childDP = dfs(v);
            dpNo = merge(dpNo, childDP[0]);        // parent skipped => child uses dpNo
            dpWith = merge(dpWith, childDP[1]);    // parent bought => child uses dpWith
        }

        int[] newNo = dpNo.clone();
        int[] newWith = dpNo.clone();

        // Consider buying u
        int fullCost = present[u];
        int halfCost = present[u] / 2;
        int profitFull = future[u] - fullCost;
        int profitHalf = future[u] - halfCost;

        for (int b = fullCost; b <= budget; b++)
            newNo[b] = Math.max(newNo[b], dpWith[b - fullCost] + profitFull);

        for (int b = halfCost; b <= budget; b++)
            newWith[b] = Math.max(newWith[b], dpWith[b - halfCost] + profitHalf);

        return new int[][] {newNo, newWith};
    }

    private int[] merge(int[] A, int[] B) {
        int[] merged = new int[budget + 1];
        Arrays.fill(merged, Integer.MIN_VALUE);
        merged[0] = 0;
        for (int i = 0; i <= budget; i++) {
            if (A[i] < 0) continue;
            for (int j = 0; j + i <= budget; j++) {
                merged[i + j] = Math.max(merged[i + j], A[i] + B[j]);
            }
        }
        return merged;
    }
}
