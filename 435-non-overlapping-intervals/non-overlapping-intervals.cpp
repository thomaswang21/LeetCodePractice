
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0; // 如果为空直接返回0

        // 按右端点升序排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int count = 0; // 记录要删除的区间数量
        int end = intervals[0][1]; // 当前保留区间的右端点

        for (int i = 1; i < intervals.size(); i++) {
            // 如果当前区间的左端点 < 上一个区间的右端点，说明重叠
            if (intervals[i][0] < end) {
                count++; // 删除一个区间
            } else {
                end = intervals[i][1]; // 不重叠，更新右端点
            }
        }

        return count; // 返回最少删除数量
    }
};

