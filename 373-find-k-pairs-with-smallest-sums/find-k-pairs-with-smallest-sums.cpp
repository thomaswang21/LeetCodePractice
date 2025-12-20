
// 思路：
// 题目要求找到两个有序数组中和最小的k对数对。
// 因为数组是升序的，所以最小的和一定出现在前面的元素组合中。
// 我们可以使用最小堆（优先队列）来动态维护当前可能的最小和的数对。
// 初始时，将nums1的第一个元素与nums2的第一个元素配对入堆。
// 每次取出堆顶（当前最小和的数对），并将该数对的下一个可能组合入堆。
// 为避免重复，我们只推进nums2的索引。

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0 || n2 == 0 || k == 0) return result;

        // 小顶堆，存储三元组：(和, nums1的索引, nums2的索引)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // 初始化，将nums1的前若干个元素与nums2[0]配对入堆
        for (int i = 0; i < n1 && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        // 取出k个最小的数对
        while (k > 0 && !minHeap.empty()) {
            vector<int> top = minHeap.top();
            minHeap.pop();
            int i = top[1];
            int j = top[2];
            result.push_back({nums1[i], nums2[j]});
            k--;

            // 将下一个可能的组合入堆
            if (j + 1 < n2) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};
