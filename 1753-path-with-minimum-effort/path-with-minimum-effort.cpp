#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();

        // effort[r][c] 表示从 (0,0) 到 (r,c) 的最小体力消耗
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));

        // 小顶堆，元素为 {effort, row, col}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        effort[0][0] = 0;

        vector<int> dir = {0, 1, 0, -1, 0};

        while (!pq.empty()) {
            auto [currEffort, r, c] = pq.top();
            pq.pop();

            // 抵达右下角
            if (r == rows - 1 && c == cols - 1) return currEffort;

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int nextEffort = max(currEffort, abs(heights[r][c] - heights[nr][nc]));

                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        pq.push({nextEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};
