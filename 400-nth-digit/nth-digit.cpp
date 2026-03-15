

class Solution {
public:
    int findNthDigit(int n) {
        long long digit = 1; // 当前位数
        long long start = 1; // 当前区间起始数字
        long long count = 9; // 当前区间总位数

        // 1. 找到 n 所在的位数区间
        while (n > count) {
            n -= count; // 减去前面区间的位数
            digit++; // 位数增加
            start *= 10; // 区间起始数字变为 10, 100, 1000...
            count = 9 * start * digit; // 当前区间总位数
        }

        // 2. 找到具体的数字
        long long num = start + (n - 1) / digit;

        // 3. 找到该数字中的具体哪一位
        string s = to_string(num);
        int index = (n - 1) % digit;
        return s[index] - '0';
    }
};
