class StockSpanner {
            // 只存价格
    vector<int> history;    // 存过去的价格，用于计算跨度

public:
    StockSpanner() {
        
    }

    int next(int price) {
        int count = 1;  // 至少包含今天自己
        int n = history.size();

        // 从右往左遍历历史价格，统计连续 <= price 的天数
        for (int i = n - 1; i >= 0; i--) {
            if (history[i] <= price) {
                count++;
            } else {
                break; // 遇到比今天大的价格就停止
            }
        }

        // 保存今天价格
        history.push_back(price);

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */