class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // 去重：第 1 个数
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // 去重：第 2 个数
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] 
                                  + nums[j]
                                  + nums[left]
                                  + nums[right];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // 去重：第 3、4 个数
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;

                    } else if (sum > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        return res;
    }
};
