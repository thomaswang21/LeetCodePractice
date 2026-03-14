

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 按左端点升序，右端点降序排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1]; // 左端点相同则右端点大的在前
            return a[0] < b[0]; // 否则左端点小的在前
        });

        int count = 0; // 记录剩余区间数量
        int maxRight = 0; // 当前最远的右端点

        // 遍历所有区间
        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];  // 当前区间左端点
            int right = intervals[i][1]; // 当前区间右端点

            // 如果当前区间的右端点 <= maxRight，说明被覆盖
            if (right <= maxRight) {
                continue; // 被覆盖，不计数
            } else {
                count++; // 没被覆盖，计数+1
                maxRight = right; // 更新最远右端点
            }
        }

        return count; // 返回剩余区间数量
    }
};


