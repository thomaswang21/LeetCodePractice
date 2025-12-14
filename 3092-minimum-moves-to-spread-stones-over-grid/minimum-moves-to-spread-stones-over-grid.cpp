
// 思路说明：
// 题目要求将 3x3 网格中的石头分配，使每个格子恰好有 1 个石头，求最少移动次数。
// 每次移动只能将一个石头从一个格子移动到相邻格子（上下左右）。
// 解法：
// 1. 记录所有石头过多的格子（>1）和石头不足的格子（=0）。
// 2. 对于每个多余石头的格子，计算它移动到每个空格的曼哈顿距离。
// 3. 使用回溯（DFS）或最小匹配搜索，找到最小的总移动距离。
// 因为 3x3 网格规模很小（最多 9 个格子），暴力搜索可行。

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int ans = INT_MAX; // 记录最小移动次数

    // 回溯函数：匹配多余石头与空格
    void dfs(vector<pair<int,int>>& extra, vector<pair<int,int>>& empty, int idx, int cost, vector<bool>& used) {
        if (idx == extra.size()) { // 所有多余石头已匹配完
            if (cost < ans) ans = cost;
            return;
        }
        for (int i = 0; i < empty.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                int dist = abs(extra[idx].first - empty[i].first) + abs(extra[idx].second - empty[i].second);
                dfs(extra, empty, idx + 1, cost + dist, used);
                used[i] = false;
            }
        }
    }

    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> extra; // 存放多余石头的格子
        vector<pair<int,int>> empty; // 存放空格子

        // 收集多余石头位置和空格位置
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 1) {
                    for (int k = 1; k < grid[i][j]; k++) { // 多余部分
                        extra.push_back({i, j});
                    }
                } else if (grid[i][j] == 0) {
                    empty.push_back({i, j});
                }
            }
        }

        vector<bool> used(empty.size(), false);
        dfs(extra, empty, 0, 0, used);
        return ans;
    }
};


