class Solution{
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size(), leftmin = prices[0], rightmax = prices[n-1];
        vector<int> leftprofit(n,0),rightprofit(n,0);
        for(int i=1;i<n;i++){
            leftmin = min(leftmin, prices[i]);
            leftprofit[i] = max(leftprofit[i-1], prices[i]-leftmin);
            rightmax = max(rightmax, prices[n-1-i]);
            rightprofit[n-1-i] = max(rightprofit[n-i], rightmax-prices[n-1-i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans,leftprofit[i]+rightprofit[i]);
        return ans;
    }
};