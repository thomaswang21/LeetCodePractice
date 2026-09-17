class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 0;
        for (int w : weights) {
            l = max(l, w); // 最小运载能力至少得能装下最重的那一件货物
            r += w;        // 最大运载能力是一次性装下所有货物
        }
        
        // 使用标准的 [l, r] 双闭区间二分模板
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (f(weights, mid) <= days) {
                // 当前运载能力 mid 能够按时运完，但我们要找更小的运力
                // 所以将右边界左移，排除当前值
                r = mid - 1;
            } else {
                // 当前运载能力 mid 太小，导致耗时超过 days
                // 必须增加运力，所以左边界右移
                l = mid + 1;
            }
        }
        
        // 寻找“满足条件的最小值”，跳出循环时 l 总是指向这个 Lower Bound
        return l;
    }

private:
    // 定义：当运载能力为 x 时，需要 f(x) 天运完所有货物
    int f(vector<int>& weights, int x) {
        int days = 0;
        for (int i = 0; i < weights.size(); ) {
            int cap = x;
            while (i < weights.size()) {
                if (cap < weights[i]) break;
                else cap -= weights[i];
                i++;
            }
            days++;
        }
        return days;
    }
};