class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int prefix = 0, suffix = 0;

        for (int i = 0; i < n; i++) {
            // 计算从左往右的前缀乘积
            if (prefix == 0)
                prefix = 1;
            prefix *= nums[i];

            // 计算从右往左的后缀乘积
            if (suffix == 0)
                suffix = 1;
            suffix *= nums[n - 1 - i];

            // 更新最大值
            res = max(res, max(prefix, suffix));
        }

        return res;
    }
};
