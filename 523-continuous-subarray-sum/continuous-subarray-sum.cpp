#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < preSum.size(); i++) {
            int val = preSum[i] % k;
            if (!valToIndex.count(val)) {
                valToIndex[val] = i;
            }
        }
        for (int i = 1; i <preSum.size(); i++) {
            int need = preSum[i] % k;
            if (valToIndex.count(need)) {
                if (i - valToIndex[need] >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
};
