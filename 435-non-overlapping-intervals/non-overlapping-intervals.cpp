class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 按右端点排序（贪心）
        sort(intervals.begin(), intervals.end(), 
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });
        
        int removed = 0;
        int prevEnd = intervals[0][1]; // 最后选择的区间的右端点

        // 从第二个区间开始
        for (int i = 1; i < intervals.size(); i++) {
            // 如果重叠：当前区间的start < 上一个区间的end
            if (intervals[i][0] < prevEnd) {
                removed++;  // 需要删掉当前区间
            } else {
                prevEnd = intervals[i][1]; // 不重叠，更新prevEnd
            }
        }

        return removed;
    }
};
