class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minP = INT_MAX; // 将初始最小值设为最大整数
        for(int i = 0; i < prices.size(); i++){
            if(minP > prices[i]){
                minP = prices[i];
            }
            res = max(res, prices[i] - minP);
        }
        return res;
    }
};