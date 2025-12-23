class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, n = prices.length;
        for(int i=0;i<n-1;i++){
            if(prices[i] < prices[i+1]){
                int buy = prices[i], sell = prices[i+1];
                while(i<n-1 && prices[i+1]>=sell){
                    sell = prices[i+1];
                    i++;
                }
                ans += sell-buy;
            }
        }

        return ans;
    }
}