class StockSpanner {
private:
    stack<pair<int,int>> stk; // {idx, value}
    int idx;
public:
    StockSpanner() {
        idx = 0;
        stk.push({-1,INT_MAX});
    }
    
    int next(int price) {
        while(!stk.empty() && stk.top().second<=price){
            stk.pop();
        }

        int ans = idx-stk.top().first;
        stk.push({idx++,price});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */