class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, sell = INT_MIN, ans = 0;
        for(int &price: prices){
            if(price < buy)
                sell = buy = price;
            else if(price > sell)
                sell = price;
            
            ans = max(ans, sell-buy);
        }
        return ans;
    }
};