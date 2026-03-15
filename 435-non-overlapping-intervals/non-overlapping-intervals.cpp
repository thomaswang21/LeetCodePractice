class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 【统一排序】按左端点升序，左相同按右降序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            // 发现重叠
            if (intervals[i][0] < end) {
                count++; // 必须删掉一个
                // 【核心改变】贪心策略：保留结束比较早的那个区间，更新较小的 end
                end = min(end, intervals[i][1]); 
            } else {
                // 没有重叠，正常推进右边界
                end = intervals[i][1];
            }
        }

        return count;
    }
};

