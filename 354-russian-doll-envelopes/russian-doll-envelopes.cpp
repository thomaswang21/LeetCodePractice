#include <vector>
#include <algorithm>

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        std::sort(envelopes.begin(), envelopes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return b[1] < a[1]; // 宽度相同，高度降序
            } else {
                return a[0] < b[0]; // 宽度升序
            }
        });

        // 提取高度数组
        std::vector<int> height(n);
        for (int i = 0; i < n; i++)
            height[i] = envelopes[i][1];

        return lengthOfLIS(height);
    }

    // 返回 nums 中 LIS 的长度（O(n log n) 方法）
    int lengthOfLIS(std::vector<int>& nums) {
        int piles = 0, n = nums.size();
        std::vector<int> top(n);
        for (int i = 0; i < n; i++) {
            int poker = nums[i];
            int left = 0, right = piles;
            // 二分查找
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] >= poker)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (left == piles) piles++;
            top[left] = poker;
        }
        return piles;
    }
};
