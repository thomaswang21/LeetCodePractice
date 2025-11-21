
// 思路：
// 题目要求找到每一天需要等待多少天才能遇到更高的温度。
// 使用单调栈（从栈顶到栈底温度递减）。
// 从后往前遍历数组：
// 1. 当栈不为空且当前温度 >= 栈顶温度时，弹出栈顶（因为当前温度更高或相等，栈顶无用）。
// 2. 若栈不为空，则答案为栈顶索引减当前索引，否则为 0。
// 3. 将当前索引压入栈。
// 时间复杂度 O(n)，空间复杂度 O(n)。

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // 结果数组
        stack<int> st; // 存储索引的单调栈

        // 从后往前遍历
        for (int i = n - 1; i >= 0; i--) {
            // 弹出栈中比当前温度低或相等的元素
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            // 如果栈不为空，说明栈顶是下一个更高温度的索引
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // 当前索引入栈
            st.push(i);
        }

        return ans;
    }
};
