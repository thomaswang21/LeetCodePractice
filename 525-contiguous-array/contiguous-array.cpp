#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        // 计算 nums 的前缀和
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                preSum[i + 1] = preSum[i] - 1;
            } else {
                preSum[i + 1] = preSum[i] + 1;
            }
        }
        // 前缀和到索引的映射，方便快速查找所需的前缀和
        unordered_map<int, int> valToIndex;
        int res = 0;
        for (int i = 0; i < nums.size()+1; i++) {
            // 如果这个前缀和还没有对应的索引，说明这个前缀和第一次出现，记录下来
            if (valToIndex.find(preSum[i]) == valToIndex.end()) {
                valToIndex[preSum[i]] = i;
            } else {
                // 这个前缀和已经出现过了，则找到一个和为 0 的子数组
                res = max(res, i - valToIndex[preSum[i]]);
            }
            // 因为题目想找长度最大的子数组，所以前缀和索引应尽可能小
        }
        return res;
    }
};