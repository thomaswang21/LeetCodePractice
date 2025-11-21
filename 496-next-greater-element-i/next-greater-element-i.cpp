
// 思路：
// 题目要求找到 nums1 中每个元素在 nums2 中的下一个更大元素。
// 因为 nums1 是 nums2 的子集，可以先在 nums2 中计算每个元素的下一个更大值。
// 使用单调栈从右往左遍历 nums2：
// 1. 当栈不为空且当前元素 >= 栈顶元素时，弹出栈顶。
// 2. 若栈不为空，栈顶即为当前元素的下一个更大元素，否则为 -1。
// 3. 将当前元素入栈。
// 最后用哈希表存储 nums2 中每个元素对应的下一个更大值，再根据 nums1 构造答案。
// 时间复杂度 O(n)，空间复杂度 O(n)。

#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // 存储每个元素的下一个更大值
        stack<int> st; // 单调栈

        // 从右往左遍历 nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            // 弹出比当前元素小或相等的元素
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            // 若栈不为空，栈顶即为下一个更大元素，否则为 -1
            if (!st.empty()) {
                nextGreater[num] = st.top();
            } else {
                nextGreater[num] = -1;
            }
            // 当前元素入栈
            st.push(num);
        }

        // 构造结果
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};
