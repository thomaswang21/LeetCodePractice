

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int hold = -prices[0]; // 第一天买入
        int sold = 0;          // 第一天卖出不可能
        int rest = 0;          // 第一天休息收益为0

        for (int i = 1; i < n; i++) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_rest = rest;

            hold = max(prev_hold, prev_rest - prices[i]);
            sold = prev_hold + prices[i];
            rest = max(prev_rest, prev_sold);
        }

        return max(sold, rest);
    }
};

