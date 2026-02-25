
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix; // 前缀和数组
public:
    // 构造函数：计算前缀和
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i]; // prefix[i+1] 表示前 i 个元素之和
        }
    }

    // 查询区间和
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

