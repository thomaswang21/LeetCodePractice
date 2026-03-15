

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0; // 统计 5 的个数
        while (n > 0) { // 不断除以 5
            n /= 5; // 每次统计有多少个 5
            count += n; // 累加 5 的个数
        }
        return count; // 返回末尾 0 的数量
    }
};

