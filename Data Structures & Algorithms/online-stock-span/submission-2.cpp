class StockSpanner {
public:
    StockSpanner() {
        
    }
    int idx = 0;
    stack<pair<int, int>> s;
    int next(int price) {
        int ans;
        while(!s.empty() && s.top().first <= price)
            s.pop();
        if(!s.empty())
            ans = idx - s.top().second;
        else
            ans = idx + 1;
        s.push({price, idx++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */