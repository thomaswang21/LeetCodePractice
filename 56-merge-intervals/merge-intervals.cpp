

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 如果区间为空，直接返回空结果
        if (intervals.empty()) return {};

        // 按区间起点排序
        sort(intervals.begin(), intervals.end());

        // 结果数组
        vector<vector<int>> merged;
        // 将第一个区间加入结果
        merged.push_back(intervals[0]);

        // 遍历剩余区间
        for (int i = 1; i < intervals.size(); i++) {
            // 获取结果中最后一个区间的引用
            vector<int>& last = merged.back();

            // 如果当前区间的起点 <= 上一个区间的终点，说明重叠
            if (intervals[i][0] <= last[1]) {
                // 更新终点为两者中较大的那个
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // 否则直接加入结果
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};



