class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // 关键修复：处理边界情况
        if (intervals.empty()) {
            return true;
        }

        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        int end = intervals[0][1];
        
        for (int i = 1; i < n; i++) {
            // 如果当前会议的开始时间 < 上一个会议的结束时间，说明重叠
            if (intervals[i][0] < end) {
                return false;
            } else {
                // 更新当前的最晚结束时间
                // 注意：由于已经排过序，直接取当前会议结束时间即可
                end = intervals[i][1];
            }
        }
        return true;
    }
};