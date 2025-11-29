
// 思路：从末尾开始加1，若有进位则继续向前传播
// 若最高位仍有进位，则在最前面插入1
// 时间复杂度O(n)，空间复杂度O(1)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i]++; // 当前位加1
            if (digits[i] < 10) return digits; // 无进位，直接返回
            digits[i] = 0; // 有进位，当前位归零
        }
        // 若最高位有进位
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
