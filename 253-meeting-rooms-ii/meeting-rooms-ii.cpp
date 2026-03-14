class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 1. 按照开始时间升序排序
        sort(intervals.begin(), intervals.end());

        // 2. 创建一个小顶堆，用于存储每个会议室的“结束时间”
        // 堆顶永远是当前最早结束的会议室
        priority_queue<int, vector<int>, greater<int>> pq;

        // 3. 放入第一个会议的结束时间
        pq.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {
            // 如果当前会议的开始时间 >= 堆顶会议的结束时间
            // 说明有一个房间空出来了，可以复用
            if (intervals[i][0] >= pq.top()) {
                pq.pop(); // 弹出旧的结束时间
            }
            
            // 无论是否复用，都要把当前会议的结束时间放进去
            // 如果复用了，相当于更新了那个房间的结束时间
            // 如果没复用，相当于新开了一间房
            pq.push(intervals[i][1]);
        }

        // 堆的大小就是我们需要的最少房间数
        return pq.size();
    }
};