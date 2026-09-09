#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // 双端队列，存储的是元素的索引，而不是具体的值
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. 如果队首的索引已经超出了当前滑动窗口的范围，则将其移除
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // 2. 保持队列的单调递减性质：
            // 从队尾依次移除所有小于等于当前元素 nums[i] 的索引。
            // 因为当前元素不仅更大，而且在窗口中存留的时间更长，
            // 之前那些较小的元素绝对不可能成为现在或未来的最大值。
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // 3. 将当前元素的索引加入队尾
            dq.push_back(i);
            
            // 4. 当遍历的元素数量达到窗口大小 k 时（即 i >= k - 1），
            // 队首元素对应的就是当前窗口的最大值，将其加入结果数组
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};