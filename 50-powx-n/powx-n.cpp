

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // 转换为 long long 防止溢出
        if (N < 0) { // 若指数为负
            x = 1 / x; // 取倒数
            N = -N;    // 取正
        }
        return fastPow(x, N); // 调用快速幂函数
    }

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0; // 任何数的 0 次方为 1
        double half = fastPow(x, n / 2); // 递归计算一半
        if (n % 2 == 0) {
            return half * half; // 若 n 为偶数
        } else {
            return half * half * x; // 若 n 为奇数
        }
    }
};

