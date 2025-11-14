class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 最远目的地是 1000（题目约束），我们就建立一个 1001 长度的数组
        vector<int> diff(1001, 0); // 差分数组

        for (auto& trip : trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            diff[from] += num;     // 上车
            diff[to] -= num;       // 下车
        }

        // 恢复原数组（前缀和），同时判断是否超过 capacity
        int cur = 0;
        for (int i = 0; i <= 1000; ++i) {
            cur += diff[i];
            if (cur > capacity) return false;
        }

        return true;
    }
};
