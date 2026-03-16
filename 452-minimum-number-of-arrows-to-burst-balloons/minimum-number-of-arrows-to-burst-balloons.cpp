
// 时间复杂度: O(n log n)  (排序所需时间)
// 空间复杂度: O(1)

// 详细思路：
// 1. 每个气球是一个区间 [x_start, x_end]。
// 2. 一支箭可以射穿所有与它射击位置 x 相交的区间。
// 3. 我们需要最少的箭数来覆盖所有区间。
// 4. 这与“合并区间”问题类似，使用贪心算法解决。
// 5. 先按区间右端点从小到大排序。
// 6. 从第一个区间开始，记录当前箭的位置为当前区间的右端点。
// 7. 遍历后续区间，如果当前区间的左端点 <= 当前箭位置，说明能被同一箭射中，跳过。
// 8. 否则需要新箭，将箭位置更新为当前区间的右端点。
// 9. 最后返回箭数。

// 核心思想：
// 贪心地在最右端点处射箭，尽量覆盖更多区间。

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0; // 如果没有气球，返回0

        // 按右端点排序
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1; // 至少需要一支箭
        int end = points[0][1]; // 当前箭的位置（第一个区间的右端点）

        for (int i = 1; i < points.size(); i++) {
            // 如果当前气球的起点大于当前箭位置，说明需要新箭
            if (points[i][0] > end) {
                arrows++;             // 新箭
                end = points[i][1];   // 更新箭位置
            }
            // 否则当前气球已被射中，不需要新箭
        }

        return arrows;
    }
};

