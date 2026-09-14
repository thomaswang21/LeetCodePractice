class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;           // 窗口的左边界
        int max_len = 0;        // 记录最大长度
        int zero_count = 0;     // 记录当前窗口内 0 的个数

        // right 是窗口的右边界
        for (int right = 0; right < nums.size(); right++) {
            // 如果遇到了 0，增加 0 的计数
            if (nums[right] == 0) {
                zero_count++;
            }

            // 如果窗口内 0 的个数超过了允许的 k 个，必须缩小窗口
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++; // 左边界右移
            }

            // 更新最大长度
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};