class StockSpanner {
private:
    stack<pair<int,int>> stk; // {price,span}
public:
    StockSpanner() {}
    
    int next(int price) {
        int currSpan = 1;
        while(!stk.empty() && stk.top().first <= price){
            currSpan += stk.top().second;
            stk.pop();
        }

        stk.push({price,currSpan});
        
        return currSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */