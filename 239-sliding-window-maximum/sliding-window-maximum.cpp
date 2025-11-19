#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // 存储索引，保证 nums[dq.front()] 是当前窗口最大值

        for (int i = 0; i < nums.size(); ++i) {
            // -------- 移除窗口外的元素 --------
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // -------- 移除比当前元素小的元素（保持递减） --------
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // -------- 将当前元素加入队列 --------
            dq.push_back(i);

            // -------- 当窗口大小 >= k，记录答案 --------
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
