class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = 1, smoothDescentCnt = 1;
        for(int i=1;i<prices.length;i++){
            if(prices[i] != prices[i-1]-1){
                smoothDescentCnt = 0;
            }
            smoothDescentCnt++;

            ans += smoothDescentCnt;
        }

        return ans;
    }
}