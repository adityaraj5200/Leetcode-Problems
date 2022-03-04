class Solution{
public:
    double champagneTower(int poured, int query_row, int query_glass){
        vector<double> dp(1,(double)(poured)), next;
        while(query_row--){
            next = vector<double>(dp.size()+1,0.0);
            for(int i=0;i<dp.size();i++){
                if(dp[i]>1){
                    double extra = (dp[i]-1)/2.0;
                    next[i] += extra;
                    next[i+1] += extra;
                }
            }
            dp = next;
        }
        
        return query_glass >= dp.size() ? 0.0 : min(1.0,dp[query_glass]);
    }
};