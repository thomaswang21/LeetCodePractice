#include <iostream>

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int res = 9;
        // 计算 n 位数的阶乘，共有几种不同数字的排列组合
        for (int i = 1; i < n; i++) {
            res *= (10 - i);
        }
        // 最后要加上 n - 1 位数的排列组合
        return res + countNumbersWithUniqueDigits(n - 1);
    }
};