class Solution {
public:
    // 手写二分：在有序数组 a 中找到第一个 >= x 的位置
    // 时间复杂度 O(log n)，空间复杂度 O(1)
    int firstGreaterEqual(vector<int>& a, int x) {
        // l 为搜索左边界，r 为搜索右边界（开区间右端点为 a.size()）
        int l = 0;                          // 左边界初始化为0
        int r = (int)a.size();              // 右边界初始化为数组长度
        while (l < r) {                     // 当左右边界未相遇时循环
            int mid = l + (r - l) / 2;      // 计算中点，防止溢出
            if (a[mid] < x) {               // 如果中点值小于目标x，答案在右半段
                l = mid + 1;                // 收缩左边界到 mid+1
            } else {                        // 否则中点值 >= x，答案在左半段（含中点）
                r = mid;                    // 收缩右边界到 mid
            }
        }
        return l;                           // l 即为第一个 >= x 的位置
    }

    // 主函数：返回最多能嵌套的信封数量
    // 时间复杂度 O(n log n)，空间复杂度 O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 若输入为空，直接返回0
        if (envelopes.empty()) {            // 检查是否为空
            return 0;                       // 空输入无可嵌套
        }

        // 自定义排序：按宽度升序；若宽度相同按高度降序
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) {             // 如果宽度不同
                return a[0] < b[0];         // 宽度小的在前
            } else {                         // 宽度相同
                return a[1] > b[1];         // 高度大的在前（关键）
            }
        });

        // 提取高度并在其上做严格递增LIS
        vector<int> tails;                  // tails[k] 为长度 k+1 的序列的最小结尾高度
        tails.reserve(envelopes.size());    // 预留空间以减少扩容

        for (size_t i = 0; i < envelopes.size(); ++i) { // 遍历每个信封
            int h = envelopes[i][1];        // 取出当前信封的高度
            int pos = firstGreaterEqual(tails, h); // 找到第一个 >= h 的位置
            if (pos == (int)tails.size()) { // 如果位置在数组末尾，说明 h 可延长序列
                tails.push_back(h);         // 追加 h，序列长度增加
            } else {                        // 否则，用 h 替换该位置，保持更小的结尾
                tails[pos] = h;             // 替换以优化将来接入更小的高度
            }
        }

        return (int)tails.size();           // tails 的长度即为最大套娃数量
    }
};