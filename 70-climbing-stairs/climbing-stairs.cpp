
// 思路：
// 这是 LeetCode 第 70 题 Climbing Stairs（爬楼梯）
// 每次可以爬 1 或 2 阶台阶，问到达第 n 阶有多少种不同方法。
// 这是经典的动态规划问题，等价于斐波那契数列。
// 状态转移方程：f(n) = f(n - 1) + f(n - 2)
// 初始条件：f(1) = 1, f(2) = 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 若台阶数小于等于 2，直接返回 n
        if (n <= 2) return n;

        int a = 1; // f(1)
        int b = 2; // f(2)
        int c = 0; // 临时变量存放 f(i)

        // 从第 3 阶开始迭代
        for (int i = 3; i <= n; i++) {
            c = a + b; // f(i) = f(i-1) + f(i-2)
            a = b;     // 更新 f(i-2)
            b = c;     // 更新 f(i-1)
        }

        return b; // 返回 f(n)
    }
};


// 该算法时间复杂度为 O(n)，空间复杂度为 O(1)，是最优解法。