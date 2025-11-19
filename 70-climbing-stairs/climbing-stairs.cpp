
// 思路：
// 动态规划，f[i] 表示到达第 i 阶的方法数
// 状态转移：f[i] = f[i-1] + f[i-2]
// 初始条件：f[1] = 1, f[2] = 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n; // 处理小规模情况

        vector<int> f(n + 1); // 创建长度为 n+1 的数组
        f[1] = 1;
        f[2] = 2;

        for (int i = 3; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2]; // 状态转移
        }

        return f[n]; // 返回结果
    }
};


// 复杂度：时间 O(n)，空间 O(n)。  
// 若想进一步优化，可用两个变量代替数组，将空间降为 O(1)。


