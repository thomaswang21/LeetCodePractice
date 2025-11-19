class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;   // 大顶堆：{值, 下标}
        vector<int> res;
        int left = 0;  // left 是窗口左端

        for (int right = 0; right < nums.size(); right++) {

            // -------- 扩大窗口：加入 right 元素 --------
            pq.push({nums[right], right});

            // -------- 如果窗口超过 k，缩小窗口 --------
            while (right - left + 1 > k) {
                left++; // 移动左指针
            }

            // -------- 当窗口大小刚好 = k，处理答案 --------
            if (right - left + 1 == k) {

                // 堆顶可能是过期元素（在窗口左边界之前），需要把它弹掉
                while (!pq.empty() && pq.top().second < left) {
                    pq.pop();
                }

                // 此时堆顶就是窗口最大值
                res.push_back(pq.top().first);
            }
        }

        return res;
    }
};
