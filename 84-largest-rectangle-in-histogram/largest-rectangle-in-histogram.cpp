
// 思路：使用单调栈来求解直方图中最大的矩形面积
// 核心思想：
// 1. 维护一个单调递增栈，栈中存储的是柱子的下标
// 2. 当遇到比栈顶柱子矮的柱子时，说明以栈顶柱子为高的矩形结束
// 3. 弹出栈顶元素，计算以该柱子为高的最大矩形面积
// 4. 最后清空栈中剩余元素，计算剩余矩形面积
// 时间复杂度：O(n)，空间复杂度：O(n)

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // 单调递增栈，存储柱子的下标
        int maxArea = 0; // 最大矩形面积
        heights.push_back(0); // 添加哨兵，方便统一处理栈中剩余元素

        for (int i = 0; i < heights.size(); i++) {
            // 当当前柱子比栈顶柱子矮时，开始计算面积
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()]; // 当前矩形的高度
                st.pop();
                int left;
                if (st.empty()) {
                    left = 0;
                } else {
                    left = st.top() + 1;
                }
                int width = i - left; // 宽度
                int area = h * width; // 面积
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            st.push(i); // 当前柱子入栈
        }

        return maxArea;
    }
};
