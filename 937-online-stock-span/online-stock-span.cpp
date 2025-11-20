class StockSpanner {
    // int[] 记录 {价格，小于等于该价格的天数} 二元组
    stack<pair<int, int>> stk;

public:
    int next(int price) {
        // 算上当天
        int count = 1;
        // 单调栈模板
        while (!stk.empty() && price >= stk.top().first) {
            // 挤掉价格低于 price 的记录
            pair<int, int> prev = stk.top();
            stk.pop();
            // 计算小于等于 price 的天数
            count += prev.second;
        }
        stk.push({price, count});

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */